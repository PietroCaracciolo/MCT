// Copyright (c) 2025 Pietro Caracciolo di Torella
// Licensed under the BSD 3-Clause License (see LICENSE file).

#ifndef UPDATE_HEADER_H
#define UPDATE_HEADER_H

#include "libraries.h"
#include "utils.h"
#include "parameters.h"
#include "interactions.h"
#include "state.h"

/**
 * Header where we define the functions required to make a Monte Carlo update.
 */

namespace real_model_space {

/**
 * @brief Method to perform a Monte Carlo Update.
 *
 * This definition is required for the abstract model class.
 *
 * @param[in,out] state     Current configuration of the system.
 * @param[in] interactions  Structure containing details on the energetics. Used in the Metropolis acceptance criterion. 
 * @param[in] parameters    Structure containing all the update options (eg. "_update_topology", "_update_particles"). 
 */
  void updateSystem(StateStruct &state, 
                  InteractionStruct &interactions, 
                  ModelParametersStruct &parameters, 
                  double T);
}

#endif // UPDATE_HEADER_H
