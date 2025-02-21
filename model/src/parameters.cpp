// Copyright (c) 2025 Pietro Caracciolo di Torella
// Licensed under the BSD 3-Clause License (see LICENSE file).

#include "parameters.h"

namespace real_model_space {

void parseParameters(ModelParametersStruct &parameters, const std::string& input_folder) {
  
  /** Open the .json input file. */
  std::string model_parameters_address = "./input/" + input_folder + "model_params.json"; 
  std::ifstream model_f(model_parameters_address);

  utils::handleExceptions([&]() {
    if (!model_f) {
      throw std::runtime_error("Could not open model_params.json");
    }

  
    json json_model_params = json::parse(model_f);

    /** Parse  energetics initialization option. */
    parameters._interactions_initialization = json_model_params.at("interactions_initialization").get<std::string>();
    if (   parameters._interactions_initialization != "random"
        && parameters._interactions_initialization != "file"  )   
    {
      throw std::runtime_error("Invalid option to initialize energetics: " + 
                  parameters._interactions_initialization + ". Valid options are: 'random', 'file'.");
    }

    /** Parse  configuration initialization option. */
    parameters._state_initialization = json_model_params.at("state_initialization").get<std::string>();
    if (   parameters._state_initialization != "random"
        && parameters._state_initialization != "file"  )   
    {
      throw std::runtime_error("Invalid option to initialize the configuration: " + 
                 parameters._state_initialization + ". Valid options are: 'random', 'file'.");
    }

    /** Parse averages options.*/
    parameters._save_E = json_model_params.at("save_average_energy").get<bool>(); 
    parameters._save_E2 = json_model_params.at("save_average_energy2").get<bool>();
    parameters._save_E4 = json_model_params.at("save_average_energy4").get<bool>();

    /** Debugging output*/
    std::cout << "[Parameters]: Parameters succesfully parsed" << std::endl;
 },"parseParameters");

}
 
void printParameters(ModelParametersStruct &parameters){
    
  std::cout << "\n------------------------------------\n";
  std::cout << "           Model  parameters\n";
  std::cout << "------------------------------------\n\n";

  std::cout << "interactions_initialization : "    << parameters._interactions_initialization << std::endl;
  std::cout << "state_initialization   : "    << parameters._state_initialization << std::endl;
  std::cout << std::boolalpha << "Save average energy                      : "   << parameters._save_E << std::endl;  
  std::cout << std::boolalpha << "Save average energy^2                    : "   << parameters._save_E2 << std::endl;  
  std::cout << std::boolalpha << "Save average energy^4                    : "   << parameters._save_E4 << std::endl;  
}

}
 
