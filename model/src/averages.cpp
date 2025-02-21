// Copyright (c) 2025 Pietro Caracciolo di Torella
// Licensed under the BSD 3-Clause License (see LICENSE file).

#include "averages.h"

namespace real_model_space {

void initializeAverages( AveragesStruct &averages,       
                         ModelParametersStruct &parameters,
                         const std::string &average_output) {
  /** Debug output. */
  std::cout << "[Averages]: Initialize averages. " << std::endl;

  /**Creation of the files where the averages will be stored*/
  if (averages._create_files) {
    createFiles(parameters, average_output);      
    averages._create_files = false;
  }
  if (parameters._save_E) {
    averages._average_energy = 0;
  }      
  if (parameters._save_E2) {
    averages._average_energy2 = 0;
  }
  if (parameters._save_E4) {
    averages._average_energy4 = 0;
  }
}
  
void updateAverages(AveragesStruct &averages,
                    StateStruct &state, 
                    ModelParametersStruct &parameters) {
  /** Debug output. */
  std::cout << "[Averages]: Update averages. " << std::endl;
 
  /** Update average energies*/
  if (parameters._save_E) {
    averages._average_energy += state._total_energy ;
  }      
  if (parameters._save_E2) {
    averages._average_energy2 += (state._total_energy*state._total_energy);
  }
  if (parameters._save_E4) {
    averages._average_energy4 += (state._total_energy*state._total_energy*state._total_energy*state._total_energy);
  }
    
}
  
void saveAverages(AveragesStruct &averages,
                  ModelParametersStruct &parameters,
                  double T,
                  int mcs_av,
                  const std::string &average_output) {

  /** Debug output. */
  std::cout << "[Averages]: Save averages. " << std::endl;

  if (parameters._save_E) {
    utils::saveScalarAverageToFile(average_output + "average_energy.txt",
                            averages._average_energy, 
                            T, 
                            mcs_av, 
                            "saveAverageEnergy"); 
  }
    
  if (parameters._save_E2) {
    utils::saveScalarAverageToFile(average_output + "average_energy2.txt",
                            averages._average_energy2,
                            T,
                            mcs_av,
                            "saveAverageEnergy2"); 
  }
    
  if (parameters._save_E4) {
    utils::saveScalarAverageToFile(average_output + "average_energy4.txt",
                            averages._average_energy4,
                            T,
                            mcs_av,
                           "saveAverageEnergy4");  
  }

}

void createFiles(ModelParametersStruct& parameters,
                 const std::string &average_output) {

  if (parameters._save_E) {
    utils::createFile(average_output + "average_energy.txt", "saveAverageEnergy");  
  }      
  if (parameters._save_E2) { 
    utils::createFile(average_output + "average_energy2.txt", "saveAverageEnergy2");  
  }      
  if (parameters._save_E4) {
    utils::createFile(average_output + "average_energy4.txt", "saveAverageEnergy4");  
  }
}

}

