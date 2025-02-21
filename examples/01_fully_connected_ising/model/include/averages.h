#ifndef AVERAGES_HEADER_H
#define AVERAGES_HEADER_H

#include "libraries.h"
#include "utils.h"
#include "parameters.h"
#include "interactions.h"
#include "state.h"
#include "update.h"

/**
 * In this header are defined all the methods and structures required to manage the averages of the observables. 
 */

namespace real_model_space {

/**
 * @brief Structure holding the averages of observables at a given temperature T.
 * 
 * This definition is required for the abstract model class
 */
 
  struct AveragesStruct {
    /** @brief Boolean variable to create the files at the beginning of the simulation 
     * 
     * As soon as the files are created this variable will be permanently set to false.  
     */
    bool _create_files = true;

    /** @brief  Average energy*/
    double _average_energy;
   
    /** @brief Average energy ^2*/
    double _average_energy2;

    /** @brief Average energy ^4*/
    double _average_energy4;

    /** @brief Magnetization */
    double _m;

 
  };

/**
 * @brief Method to initialize the averages to zero.
 *
 * This definition is required for the abstract model class.
 *
 * @param[in,out] averages    Structure where the initial averages will be stored.
 * @param[in] parameters      Structure containing all the average options (eg. "_save_E", "_save_average_color", etc.).
 *                            Determines which averages will be calculated and which don't.  
 * @param[in] average_output  Path to the output folder, where the averages wil be saved. It is required to create the
 *                            files if they haven't yet been created.
 */ 
  void initializeAverages(
      AveragesStruct &averages, 
      ModelParametersStruct &parameters,
      const std::string &average_output);

/**
 * @brief Method to update the averages using the current state of the system.
 *
 * The averages are update by just adding up the current values of the observables, the true average will be calculated 
 * in the saving step, where you divide this big sum by the number of terms that you summed (mcs_av). 
 *
 * This definition is required for the abstract model class.
 *
 * @param[in,out] averages    Structure where the averages are stored.
 * @param[in] parameters      Structure containing all the average options (eg. "_save_E", "_save_average_color", etc.).
 *                            Determines which averages will be calculated and which don't.  
 * @param[in] state           Current state of the system, used to update the averages.  
 */
  void updateAverages(
      AveragesStruct &averages, 
      StateStruct &state,
      ModelParametersStruct &parameters);

/**
 * @brief Method to save the averages.
 *
 * This definition is required for the abstract model class.
 *
 * @param[in,out] averages    Structure where the initial averages will be stored.
 * @param[in] parameters      Structure containing all the average options (eg. "_save_E", "_save_average_color", etc.).
 *                            Determines which averages will be calculated and which don't.  
 * @param[in] average_output  Path to the output folder, where the averages wil be saved. It is required to create the
 *                            files if they haven't yet been created.
 * @param[in] T               Temperature at which the averages have been calculated.
 * @param[in] mcs_av          Number of Monte Carlo steps that have been used to calculate the average.  
 */ 
  void saveAverages(
      AveragesStruct &averages, 
      ModelParametersStruct &parameters, 
      double T, 
      int mcs_av,
      const std::string &average_output);
 
/**
 * @brief Method to create the files where the averages will be stored.
 *
 * @param[in] averages        Structure where the averages are stored.
 * @param[in] parameters      Structure containing all the average options (eg. "_save_E", "_save_average_color", etc.).
 *                            Determines which averages will be saved and which don't.  
 */ 
 
  void createFiles(ModelParametersStruct& parameters,
                   const std::string &average_output);
   

}  // namespace simplex_space

#endif  // AVERAGES_HEADER_H

