#include "interactions.h"

namespace real_model_space {

/** Initialize the energetics of the model*/
void initializeInteractions(InteractionStruct &interactions,
                            ModelParametersStruct &parameters,
                            const std::string& input_folder) {

  /** @brief Example of drawing a random interaction.*/
  if (parameters._interactions_initialization == "random") {
    /** Debugging output. */
    //std::cout << "[Interactions]: Energetics initialization 'random'." << std::endl;

    /** Create a uniform distribution between 1 and 10 */
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    
    /** Random generation of J*/
    interactions._J = -1*dist(utils::rng()) / static_cast<double>(parameters._N);
    
  }
  /** @brief Example of parsing interactions from file.*/
  else if (parameters._interactions_initialization == "file") {
    /** Debugging output. */ 
    //std::cout << "[Interactions]: Energetics initialization 'file'." << std::endl ;
     
    /** Load the input file.*/ 
    std::string interactions_address = "./input/" + input_folder +"interactions.json";
    std::ifstream interactions_f(interactions_address);
    
    utils::handleExceptions([&]() {
      if (!interactions_f){
        throw std::runtime_error("Could not open interactions.json");
      }

      json json_model_interactions = json::parse(interactions_f);
      interactions._J = json_model_interactions.at("J").get<double>() / static_cast<double>(parameters._N); 


      


    }, "initializeFileInteractions");   
  }    
}

/* Print the summary of the energetics.*/
void printInteractions(InteractionStruct &interactions){
  std::cout << "\n------------------------------------\n"; 
  std::cout << "       Model Energetics\n";
  std::cout << "------------------------------------\n\n";

  std::cout << "J      : " << interactions._J << std::endl; 
  
}
 
}
