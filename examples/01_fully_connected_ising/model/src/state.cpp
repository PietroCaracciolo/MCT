#include "state.h"

namespace real_model_space {


/** @brief Example of initialization of the state. */
void initializeState(StateStruct& state,
                     InteractionStruct& interactions,
                     ModelParametersStruct &parameters,
                     const std::string &input_folder) {

  /** @brief Example of random initialization */
  if (parameters._state_initialization == "random") {
    /** Debuggign output. */
    //std::cout << "[State]: Configuration initialization 'random'. " << std::endl;

    std::uniform_int_distribution<int> dist(0, 1);
    for (int index = 0; index < parameters._N; index ++ ){
      state._spin_config.push_back(dist(utils::rng())*2-1);
    }  
  }
  /** @brief Example of random initialization */
  else if(parameters._state_initialization == "file") {
    /** Load the input file.*/ 
    std::string state_address = "./input/" + input_folder +"state.json";
    std::ifstream state_f(state_address);
    
    utils::handleExceptions([&]() {
      if (!state_f){
        throw std::runtime_error("Could not open state.json");
      }

      /** Check that the input imap is a valid input.*/ 
      json json_model_state = json::parse(state_f);

      state._spin_config = json_model_state.at("spin_config").get<std::vector<int>>();

      /** Check that state._spin_config has exactly N elements */
      if (state._spin_config.size() != static_cast<size_t>(parameters._N)) {
        throw std::runtime_error("Invalid spin configuration: expected a vector of size:" + std::to_string(parameters._N) + ".");
      }

      /** Check that all elements in state._spin_config are either 1 or -1 */
      for (int spin : state._spin_config) {
        if (spin != 1 && spin != -1) {
          throw std::runtime_error("Invalid spin value: expected only 1 or -1.");
        } 
      }
 
    }, "initializeFileState"); 
  }

  /** Debugging output. */
  //std::cout << "[State]: Initializing total energy." << std::endl; 
   
  /** Compute total energy. */
  state._total_energy = computeTotalEnergy(state, parameters, interactions);
  
  /** Debugging output. */
  std::cout << "[State]: State succesfully initialized." << std::endl;
}

void printState(StateStruct &state) {
  std::cout << "\n------------------------------------\n";
  std::cout << "       Model Initial configuration\n";
  std::cout << "------------------------------------\n\n";

  //std::cout << "Spin initial configuration: "<< std::endl; 
  //utils::printVector(state._spin_config); 
}

/** @brief Save the state to file.*/
void saveState(StateStruct &state, const std::string &state_output) {

  /** Debug output. */
  //std::cout << "[State]: Saving configuration to file. "<< std::endl;
  std::ofstream config_f(state_output + "config.txt");    
  utils::handleExceptions([&]() {
    if (config_f.is_open()) {
      utils::printVector(state._spin_config, config_f);   
      config_f.close();

    } else {
      throw std::runtime_error("Could not create " + state_output + "config.txt");
    }
  }, "saveState");

}

void printEnergy(StateStruct &state){
  std::cout<<"Total energy: "<<  state._total_energy <<std::endl;
}

double computeTotalEnergy(StateStruct& state,
                       ModelParametersStruct& parameters, 
                       InteractionStruct& interactions) {
  double total_energy = 0;
 
  for(int i = 0; i < parameters._N; i++){
    for(int j = i+1; j < parameters._N; j++){
      total_energy += interactions._J * state._spin_config[i] * state._spin_config[j];  
    } 
  }
 
  return total_energy;
}

}
