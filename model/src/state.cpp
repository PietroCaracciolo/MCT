// Copyright (c) 2025 Pietro Caracciolo di Torella
// Licensed under the BSD 3-Clause License (see LICENSE file).

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
    std::cout << "[State]: Configuration initialization 'random'. " << std::endl;    
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

    /** Debuggign output. */
    std::cout << "[State]: Configuration initialization 'file'. " << std::endl;    
    }, "initializeFileState"); 
  }

  /** Debugging output. */
  std::cout << "[State]: Initializing total energy." << std::endl; 
   
  /** Compute total energy. */
  state._total_energy = computeTotalEnergy(state, parameters, interactions);
  
  /** Debugging output. */
  std::cout << "[State]: State succesfully initialized." << std::endl;
}

void printState(StateStruct &state) {
  std::cout << "\n------------------------------------\n";
  std::cout << "       Model Initial configuration\n";
  std::cout << "------------------------------------\n\n";

}

/** @brief Save the state to file.*/
void saveState(StateStruct &state, const std::string &state_output) {

  /** Debug output. */
  std::cout << "[State]: Saving configuration to file. "<< std::endl;
  std::ofstream config_f(state_output + "config.txt");    
  utils::handleExceptions([&]() {
    if (config_f.is_open()) {
      
      config_f.close();
    } else {
      throw std::runtime_error("Could not create " + state_output + "config.txt");
    }
  }, "saveState");

}

void printEnergy(StateStruct &state){
  std::cout<<"Total energy: "<<  state._total_energy <<std::endl;
}

int computeTotalEnergy(StateStruct& state,
                       ModelParametersStruct& parameters, 
                       InteractionStruct& interactions) {
  int total_energy = 0;
  
  return total_energy;
}

}
