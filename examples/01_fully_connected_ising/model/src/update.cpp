#include "update.h"

namespace real_model_space {

void updateSystem(StateStruct &state, 
                  InteractionStruct &interactions, 
                  ModelParametersStruct &parameters, 
                  double T){
  /** Debug output. */
  //std::cout << "[Update]: updating the model configuration." << std::endl;

  static std::uniform_int_distribution<int> spin_index_dist(0, parameters._N);
 
  double Ei;  /** Initial energy */
  double Ef;  /** Final energy */

  int index;

  for (int step = 0; step < parameters._N; step++) {
    Ei = state._total_energy; 

    index = spin_index_dist(utils::rng()); 

    /**Example of update: Flip the spin */
    state._spin_config[index] = state._spin_config[index] * -1;

    /** @alert This computation could be made locally, it is suboptimal in terms of optimization. */
    Ef = computeTotalEnergy( state, parameters, interactions);

    double acceptance_probability = std::min(exp(-(Ef - Ei) / T), 1.0); 
    if ( utils::randomDouble() < acceptance_probability){
      state._total_energy = state._total_energy + Ef - Ei;
    } else {
      state._spin_config[index] = state._spin_config[index] * -1;   
    }
 }
}

}

