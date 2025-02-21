#include "update.h"

namespace real_model_space {

void updateSystem(StateStruct &state, 
                  InteractionStruct &interactions, 
                  ModelParametersStruct &parameters, 
                  double T){
  /** Debug output. */
  // std::cout << "[Update]: updating the model configuration." << std::endl;

  std::uniform_int_distribution<int> spin_index_dist(0, 1);
  std::uniform_real_distribution<double> acceptance_dist(0.0, 1.0);

  int Ei;  /** Initial energy */
  int Ef;  /** Final energy */

  Ei = computeTotalEnergy( state, parameters, interactions);

  int index = spin_index_dist(utils::rng()); 

  /**Example of update: Flip the spin */
  state._spin_config[index] = state._spin_config[index] * -1;

  Ef = computeTotalEnergy( state, parameters, interactions);

  double acceptance_probability = std::min(std::exp(-(Ef - Ei) / T), 1.0); 
  if (acceptance_dist(utils::rng()) < acceptance_probability){
    state._total_energy = state._total_energy + Ef - Ei;
  } else {
    state._spin_config[index] = state._spin_config[index] * -1;   
  }

    
}

}

