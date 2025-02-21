/**
 * This header defines the methods and structures necessary for managing the model's energetics.
 */
 
#ifndef INTERACTIONS_HEADER_H
#define INTERACTIONS_HEADER_H

#include "libraries.h"
#include "utils.h"
#include "parameters.h"

namespace real_model_space {

/**
 * @brief Structure holding all energetic information.
 */
struct InteractionStruct {
  /** @brief Example of energy: epsilon*/
  int _epsilon{10};

};

/**
 * @brief Method to initialize the energetics.
 * 
 * This definition is required for the abstract model class.
 *
 * @param[in] interactions  Structure where the energetics will be stored.
 * @param[in] parameters    Structure containing all the initialization options can be used to select 
 *                          initialization options. 
 * @param[in] input_folder  Path to the input folder, which contains energetics if the "file" 
 *                          option is selected.   
 */ 
void initializeInteractions(InteractionStruct &interactions,
                            ModelParametersStruct &parameters,
                            const std::string &input_folder);
/**
 * @brief Method to print the energetics.
 * 
 * This definition is required for the abstract model class.
 *
 * @param[in] interactions  Structure conatining the energetics. 
 */
void printInteractions(InteractionStruct &interactions);

} // namespace real_model_space

#endif // INTERACTIONS_HEADER_H

