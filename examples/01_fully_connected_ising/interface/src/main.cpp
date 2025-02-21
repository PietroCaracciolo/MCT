#include "libraries.h"
#include "mc_engine_template.h"
#include "abstract_model.h"

int main(int argc, char *argv[]) {

  if (argc < 3) {
    std::cerr << "Error: Insufficient arguments.\n"
              << "Usage: " << argv[0] << " <simulation_name> <simulation_ID> \n";
    return 1; // Exit with an error code
  }
  
  /** @brief Compose the full path to the simulation input parameters. */
  std::string folder = std::string(argv[1]);
  std::string id = std::string(argv[2]);

  std::string input_folder = folder + "/" + id + "/";
  std::cout << "\n\n[main] Input folder: " << input_folder << "\n\n"
            << std::endl;

  /** Create an instance of the model using the parameters parsed from the input
   * folder */
  abstract_model_space::Model model(input_folder);

  /** Print all model specific parameters */
  model.printModelParameters();
  model.printModelInteractions();
  model.printModelState();

  /** Create an instance of the Monte Carlo engine */
  simulation_space::MonteCarloEngine<abstract_model_space::Model>
      engine_for_simplex(input_folder);

  /** Print the parameters of the Monte Carlo simulation (eg. inital
   * temperature, final temperature, cooling schedule, etc.).*/
  engine_for_simplex.printParameters();

  /** Run the Monte Carlo simulation over the prescribed temperature range */
  engine_for_simplex.scanTemperatureRange(model);

  return 0;
}
