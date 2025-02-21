#ifndef MC_ENGINE_TEMPLATE
#define MC_ENGINE_TEMPLATE

#include "abstract_model.h"

/**
 * This header defines a template class for performing Monte Carlo Simulated
 * Annealing simulations on any generic model. The class provides methods for
 * running simulations at a fixed temperature or over a temperature range,
 * enabling efficient exploration of the model's phase space.
 *
 * The MonteCarloEngine class is templated on a Model type, allowing flexibility
 * in simulating different physical systems while maintaining a consistent
 * simulation framework.
 *
 * The class ensures modularity and adaptability, making it easy to integrate
 * with different models by simply specifying the appropriate Model type.
 */

namespace simulation_space {

template <typename Model> class MonteCarloEngine {
public:
  /**
   * @brief Constructor for the MonteCarloEngine class.
   *
   * Initializes the simulation engine by reading and parsing simulation
   * parameters from the provided input folder. These parameters include
   * temperature range, Monte Carlo step counts, cooling schedule, and output
   * settings.
   *
   * The constructor sets up the necessary attributes to control the Monte Carlo
   * Simulated Annealing process, ensuring that the simulation framework is
   * ready for execution.
   *
   * @param[in] input_folder Path to the directory containing the simulation
   * parameters.
   */
  MonteCarloEngine(const std::string &input_folder);

  /** @brief Print the simulation specific parameters (eg. initial temperature,
   * final temperature, cooling schedule, etc.)*/
  void printParameters() const;

  /**
   * @brief Perform Monte Carlo updates at a fixed temperature.
   *
   * This method updates the system state using the Metropolis acceptance rule,
   * executing (mcs_eq + mcs_av) Monte Carlo steps at a given temperature. The
   * first mcs_eq steps are used to equilibrate the system, while the subsequent
   * mcs_av steps are used to compute observable averages at that temperature.
   *
   * @param[in] simulation_model  Reference to the model being simulated.
   * @param[in] T                 Temperature at which the simulation is
   * performed.
   */
  void simulateConstantTemperature(Model &simulation_model, double T);

  /**
   * @brief Perform Monte Carlo simulation over a range of temperatures.
   *
   * This method iterates 'simulateConstantTemperature' over a predefined
   * temperature range. The temperature are calculated according to the
   * temperature range (T_i - T_f) and the cooling schedule.
   *
   * @param[in] simulation_model  Reference to the model being simulated.
   */
  void scanTemperatureRange(Model &simulation_model);

private:
  /** @brief Initial temperature*/
  double _Ti{20};

  /** @brief Final temperature*/
  double _Tf{0.01};

  /** @brief Number of temperatures*/
  int _Nt{10};

  /** @brief Number of Monte Carlo updates used to equilbrate the system*/
  int _mcs_eq{100};

  /** @brief Number of Monte Carlo updates used to perform averages of
   * observabeles*/
  int _mcs_av{100};

  /** @brief Cooling schedule (eg. "exponential", "linear")*/
  std::string _cooling_schedule{"exponential"};

  /** @brief If true the state of the system's configutation will be saved at
   * every temperature*/
  bool _checkpoint_option{false};

  /** @brief Folder where the results will be stored*/
  std::string _simulation_name{"test"};

  /** @brief Simulation id, useful to run many simulations with the same
   * parameter values */
  std::string _simulation_id{"0"};

  /** @brief Boolean variable saying wether the results folder must be created
   * ("true") or is already there ("false")*/
  bool _create_directory{true};
};

/** IMPLEMENTATION  OF THE MC ENGINE*/
template <typename Model>

/** Constructor. */
MonteCarloEngine<Model>::MonteCarloEngine(const std::string &input_folder) {

  /** Parse the parameters. */
  std::string mc_parameters_address =
      "./input/" + input_folder + "mc_params.json";
  std::ifstream mc_f(mc_parameters_address);
  utils::handleExceptions(
      [&]() {
        if (!mc_f) {
          throw std::runtime_error("Could not open mc_params.json .");
        }

        json json_mc_params = json::parse(mc_f);

        /** Parsing and validation of the final and initial temperatures. */
        _Ti = json_mc_params.at("Ti").get<double>();
        _Tf = json_mc_params.at("Tf").get<double>();
        if (_Tf > _Ti) {
          throw std::runtime_error("The initial temperature must be larger "
                                   "than the final temperature");
        }
        if (_Ti < 0) {
          throw std::runtime_error("The initial temperature must be positive");
        }
        if (_Tf < 0) {
          throw std::runtime_error("The final temperature must be positive");
        }

        /** Parsing and validation of the number of temperature values. */
        _Nt = json_mc_params.at("Nt").get<int>();
        if (_Nt <= 0) {
          throw std::runtime_error(
              "The number of temperatures must be larger than zero");
        }

        /** Parsing and validation of the number of Monte Carlo updates. */
        _mcs_eq = json_mc_params.at("mcs_eq").get<int>();
        _mcs_av = json_mc_params.at("mcs_av").get<int>();
        if (_mcs_eq < 0) {
          throw std::runtime_error(
              "Invalid value for mcs_eq: " + std::to_string(_mcs_eq) +
              ". Expected positive value.");
        }
        if (_mcs_av < 0) {
          throw std::runtime_error(
              "Invalid value for mcs_av: " + std::to_string(_mcs_av) +
              ". Expected positive value.");
        }

        /** Parsing and validation of the cooling schedule. */
        _cooling_schedule =
            json_mc_params.at("cooling_schedule").get<std::string>();
        if (_cooling_schedule != "exponential" &&
            _cooling_schedule != "linear") {
          throw std::runtime_error(
              "Invalid cooling schedule: '" + _cooling_schedule +
              "'. Valid options are 'linear' or 'exponential'.");
        }
        /** Parsing and validation of the checkpoint option. */
        _checkpoint_option = json_mc_params.at("checkpoint_option").get<bool>();

        /** Parsing and validation of the simulatin name and id. */
        _simulation_name =
            json_mc_params.at("simulation_name").get<std::string>();
        _simulation_id = json_mc_params.at("simulation_id").get<std::string>();

        /** Building the simulation name, It will correspond to its location in
         * the results folder. */
        _simulation_name = _simulation_name + "/" + _simulation_id;

        /** Parsing and validation of the directory option. (if "true" the
         * results directory must be created). */
        _create_directory = json_mc_params.at("create_directory").get<bool>();

        /** Creating the result directory if required  */
        std::filesystem::path simulation_directory =
            "results/" + _simulation_name;
        if (_create_directory) {
          if (std::filesystem::create_directories(simulation_directory)) {

            std::filesystem::path sub_directory_averages =
                simulation_directory / "averages";
            std::filesystem::path sub_directory_state =
                simulation_directory / "state";
            std::filesystem::path sub_directory_input =
                simulation_directory / "input";

            std::filesystem::create_directory(sub_directory_averages);
            std::filesystem::create_directory(sub_directory_state);
            std::filesystem::create_directory(sub_directory_input);

          } else {
            throw std::runtime_error("The directory: '" + _simulation_name +
                                     "' already exists. If you want to override set 'create_directory' to false.");
          }
        }

        /**
         * @brief Copy the input folder into the results directory.
         *
         * This ensures all input parameters and configurations are preserved,
         * preventing data loss and enabling reproducibility of the simulation.
         */
        std::filesystem::path source = "./input/" + input_folder;
        std::filesystem::path destination = simulation_directory / "input";

        std::filesystem::copy(
            source, destination,
            std::filesystem::copy_options::recursive |
                std::filesystem::copy_options::overwrite_existing);
      },
      "MonteCarloEngine");
}

template <typename Model>
void MonteCarloEngine<Model>::printParameters() const {
  std::cout << "\n------------------------------------\n";
  std::cout << "       Monte-Carlo parameters\n";
  std::cout << "------------------------------------\n\n";

  std::cout << "Initial temperature Ti                  : " << _Ti << "\n";
  std::cout << "Final temperature Tf                    : " << _Tf << "\n";
  std::cout << "Number of temperature steps Nt          : " << _Nt << "\n\n";

  std::cout << "Number of equilibration steps mcs_eq    : " << _mcs_eq << "\n";
  std::cout << "Number of averaging steps mcs_av        : " << _mcs_av
            << "\n\n";
  std::cout << "The selected cooling schedule is        : " << _cooling_schedule
            << "\n\n";
  std::cout << "Create directory                        : " << _create_directory << "\n";
  std::cout << "Simulation name                         : " << _simulation_name
            << "\n\n";
}

template <typename Model>
void MonteCarloEngine<Model>::scanTemperatureRange(Model &simulation_model) {

  double T;

  /** Construct the temperature ramp based on the cooling schedule. */
  std::vector<double> T_ramp;
  if (_cooling_schedule == "exponential") {

    /** Compute logarithms of the initial and final temperatures. */
    double log_Ti = std::log10(_Ti);
    double log_Tf = std::log10(_Tf);

    /** Step size in the logarithmic space. */
    double log_step = (log_Tf - log_Ti) / _Nt;

    /** Generate equidistant points in log-log space. */
    for (int temperature_index = 0; temperature_index <= _Nt;
         ++temperature_index) {
      double log_T = log_Ti + temperature_index * log_step;
      T_ramp.push_back(std::pow(10, log_T)); // Convert back to linear space
    }
  } else if (_cooling_schedule == "linear") {

    /** Calculate the temperature increment. */
    double dT = (_Tf - _Ti) / (_Nt - 1);

    for (int temperature_index = 0; temperature_index <= _Nt;
         temperature_index++) {

      T_ramp.push_back(_Ti + temperature_index * dT);
    }
  } else {
    /** Handle invalid cooling schedule. */
    throw std::runtime_error("Invalid cooling schedule: " + _cooling_schedule);
  }

  /** Print energy of the initial state. */
  std::cout << "Starting energy of the system" << std::endl;
  simulation_model.printModelEnergy();

  /** Apply the cooling schedule. */
  for (int temperature_index = 0; temperature_index < _Nt;
       temperature_index++) {

    T = T_ramp[temperature_index];

    /** Simulates the model at the current temperature. */
    simulateConstantTemperature(simulation_model, T);

    /** Saves the checkpoint if the checkpoint option is enabled. */
    if (_checkpoint_option) {
      simulation_model.saveModelState("./results/" + _simulation_name +
                                      "/state/" + std::to_string(T) + "_");
    }
    std::cout << "Energy at T = " << T << ":\n";
    simulation_model.printModelEnergy();
  }
  /** Saves the final structure after completing the simulation. */
  simulation_model.saveModelState("./results/" + _simulation_name + "/state/" +
                                  std::to_string(T) + "_");
}

template <typename Model>
void MonteCarloEngine<Model>::simulateConstantTemperature(
    Model &simulation_model, double T) {

  /** Equilibrates the model for _mcs_eq steps. */
  for (int step = 0; step < _mcs_eq; step++) {
    simulation_model.updateModelSystem(T);
  }

  /** Initializes the model averages. */
  simulation_model.initializeModelAverages("./results/" + _simulation_name +
                                           "/averages/");

  /** Collect the model averages for _mcs_av steps. */
  for (int step = 0; step < _mcs_av; step++) {
    simulation_model.updateModelSystem(T);
    simulation_model.updateModelAverages();
  }

  /** Saves the model averages on the file.*/
  simulation_model.saveModelAverages(
      T, _mcs_av, "./results/" + _simulation_name + "/averages/");
}

} // namespace simulation_space

#endif // MC_ENGINE_TEMPLATE
