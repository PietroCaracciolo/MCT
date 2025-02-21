#ifndef STATE_HEADER_H
#define STATE_HEADER_H

#include "libraries.h"
#include "utils.h"
#include "parameters.h"
#include "interactions.h"


/**
 * In this header are defined all the methods and structures required to manage the configuration of the model. 
 */

namespace real_model_space {

/**
 * @brief Structure holding model configuration.
 *
 * This structure contains various observables associated with the model's configuration.
 * 
 * This definition is required for the abstract model class
 */
  struct StateStruct {
    /** @brief Example configuration: two spin values. */
    std::vector<int> _spin_config;


    /** @brief Total energy of the current configuration */
    int _total_energy;
 };  

/**
 * @brief Method to initialize the system state.
 *
 * This definition is required for the abstract model class.
 *
 * @param[in,out] state     Structure where the initial configuration will be stored.
 * @param[in] interactions  Structure containing details on the energetics. Used to calculate the total 
 *                          energy of the starting configuration.
 * @param[in] parameters    Structure containing all the initialization options.
 * @param[in] input_folder  Path to the input folder, which contains initial configurations if the "file" 
 *                          option is selected. 
 */
void initializeState(StateStruct &state,
                     InteractionStruct& interactions,
                     ModelParametersStruct &parameters,
                     const std::string &input_folder);
  
/**
 * @brief Method to print the current configuration.
 * 
 * This definition is required for the abstract model class.
 *
 * @param[in] state  Structure conatining all observables associated to the current configuration. 
 *
 */                     
void printState(StateStruct &state);

/**
 * @brief Method to save the current configuration.
 * 
 * This definition is required for the abstract model class.
 *
 * @param[in] state         Structure containing all observables associated to the current configuration. 
 * @param[in] state_output  Path to the folder where the state will be saved. 
 */                     
void saveState(StateStruct &state, 
               const std::string &state_output);

/**
 * @brief Method to print the current energy.
 * 
 * This definition is required for the abstract model class.
 *
 * @param[in] state  Structure containing all observables associated to the current configuration. 
 */                      
void printEnergy(StateStruct &state);

/**
 * @brief Method to compute the total energy of the configuration.  
 * 
 * @param[in] state         Structure containing all observables associated with the network's configuration,
 * @param[in] interactions  Structure containing details on the energetics. 
 * @param[in] parameters    Structure containing all parameters required for the model's definition. 
 *
 * @return Total energy of the system in the current configuration. 
 */
int computeTotalEnergy(StateStruct& state,
                       ModelParametersStruct& parameters, 
                       InteractionStruct& interactions);

} // namespace real_model_space

#endif // STATE_HEADER_H

