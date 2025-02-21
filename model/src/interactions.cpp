// Copyright (c) 2025 Pietro Caracciolo di Torella
// Licensed under the BSD 3-Clause License (see LICENSE file).

#include "interactions.h"

namespace real_model_space {

/** Initialize the energetics of the model*/
void initializeInteractions(InteractionStruct &interactions,
                            ModelParametersStruct &parameters,
                            const std::string& input_folder) {

  /** @brief Example of drawing a random interaction.*/
  if (parameters._interactions_initialization == "random") {
    
    /** Debugging output. */
    std::cout << "[Interactions]: Energetics initialization 'random'." << std::endl; 
  }

  /** @brief Example of parsing interactions from file.*/
  else if (parameters._interactions_initialization == "file") {
    
    /** Load the input file.*/ 
    std::string interactions_address = "./input/" + input_folder +"interactions.json";
    std::ifstream interactions_f(interactions_address);
    
    utils::handleExceptions([&]() {
      if (!interactions_f){
        throw std::runtime_error("Could not open interactions.json");
      }

      json json_model_interactions = json::parse(interactions_f);
      
    /** Debugging output. */ 
    std::cout << "[Interactions]: Energetics initialization 'file'." << std::endl ;  

    }, "initializeFileInteractions");   
  }    
  std::cout << "[Interactions]: Interactions initialized sucessfully." << std::endl;
}

/* Print the summary of the energetics.*/
void printInteractions(InteractionStruct &interactions){
  std::cout << "\n------------------------------------\n"; 
  std::cout << "       Model Energetics\n";
  std::cout << "------------------------------------\n\n";
    
}
 
}
