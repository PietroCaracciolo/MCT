/**
 * This header defines the methods and structures necessary for managing the model's parameters and the 
 * simulation's options.
 */

#ifndef PARAMETERS_HEADER_H
#define PARAMETERS_HEADER_H

#include "libraries.h"
#include "utils.h"

namespace real_model_space {

/**
 * @brief Structure holding model parameters for simulation setup.
 *
 * This structure contains various parameters required for defining and 
 * configuring the model. 
 *
 * This definition is required for the abstract model class
 */
struct ModelParametersStruct {
  /** @brief Number of spins*/
  int _N{10};

  /** @brief Example of energetics initialization option (eg. default option: "random", "file"). */
  std::string  _interactions_initialization{"random"};

  /** @brief Example of state initialization option (eg. default options: "random", "file")*/
  std::string  _state_initialization{"random"};

  /** @brief Option: save average energy.*/
  bool  _save_E{true};

  /** @brief Option: save average energy^2.*/
  bool  _save_E2{true};

  /** @brief Option: save average energy^4.*/
  bool  _save_E4{true};

  /** @brief Option: save average energy^4.*/
  bool  _save_m{true};

};

/**
 * @brief Parses model parameters from an input folder.
 *
 * This function reads parameter values from the `model_params.json` file 
 * inside the specified input folder and populates the given 
 * `ModelParametersStruct` object accordingly.
 *
 * This definition is required for the abstract model class.
 *
 * @param[in,out] parameters  The structure where parsed parameters will be stored.
 * @param[in] input_folder    The path to the input folder containing the `model_params.json` file.
 */
void parseParameters(ModelParametersStruct &parameters,
                     const std::string &input_folder);

/**
 * @brief Prints model parameters.
 *
 * This function prints all the model-specific parameters by reading them 
 * from the provided `ModelParametersStruct` object.
 *
 * @param[in] parameters  The structure containing the model parameters.
 */
void printParameters(ModelParametersStruct &parameters);

}

#endif  // PARAMETERS_HEADER_H
