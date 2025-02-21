#ifndef MODEL_HEADER_H
#define MODEL_HEADER_H

/** Include the headers of a real model*/
#include "libraries.h"
#include "parameters.h"
#include "state.h"
#include "interactions.h"
#include "update.h"
#include "averages.h"

/**
 * This header defines the "abstract model" class, which offers a generic
 * interface for modeling systems. It outlines the required attributes (e.g.,
 * ModelParametersStruct, StateStruct, InteractionStruct, AveragesStruct) and
 * methods (e.g., printModelState, updateModelSystem, etc.) that must be
 * implemented by any specific model.
 *
 * Through static polymorphism, the actual implementation of these attributes
 * and methods can be customized based on the chosen "real model". The specific
 * model is determined at compile-time by selecting the appropriate header.
 */

namespace abstract_model_space {

/**
 * @brief Abstrac model class
 */
class Model {
private:
  /** @brief  Structure containing the model specific configuration parameters
   */
  real_model_space::ModelParametersStruct _parameters;

  /** @brief Structure defining the the model configuration and the observables
   * associated to it*/
  real_model_space::StateStruct _state;

  /** @brief Structure containing the energetics of the model*/
  real_model_space::InteractionStruct _interactions;

  /** @brief Structure containing the averages of model specific observables*/
  real_model_space::AveragesStruct _averages;

public:
  /**
   * @brief Constructor for the abstract model class.
   *
   * This constructor initializes an instance of the model by setting up the
   * necessary system attributes. It configures the model's parameters,
   * interactions, and state based on the provided input folder. The actual
   * implementation of these elements will be specified by the real model,
   * allowing customization based on the chosen model at compile-time.
   *
   * @param input_folder A string representing the directory containing input
   * files with model parameters. It is used to load configuration data for the
   * system's parameters, interactions, and initial state.
   */
  Model(const std::string &input_folder);

  /** @brief Print model configuration */
  void printModelParameters();

  /** @brief Print model configuration */
  void printModelState();

  /**
   * @brief Save the model's current configuration.
   *
   * This method saves the model's parameters and state to a specified output
   * folder. The state information is saved in the subdirectory
   * `state_output/state`.
   *
   * @param[in] state_output Path to the folder where the configuration should
   * be saved.
   */
  void saveModelState(const std::string &state_output);

  /** @brief  Print the model energetics*/
  void printModelInteractions();

  /** @brief  Print the model total energy*/
  void printModelEnergy();

  /**
   * @brief Perform a full Monte Carlo update of the system at a given
   * temperature.
   *
   * Updates the system state using the Metropolis criterion at the specified
   * temperature.
   *
   * @param[in] T Temperature at which the update is performed.
   */
  void updateModelSystem(double T);

  /**
   * @brief Initialize the model's averages.
   *
   * Prepares the necessary data structures for tracking system averages and
   * specifies the output directory where they will be saved.
   * The information abaout the averages is saved in the subdirectory
   * `avreage_output/averages`.
   *
   * @param[in] average_output Path to the folder where the averages will be
   * stored.
   */
  void initializeModelAverages(const std::string &average_output);

  /** @brief  Update the averages of the observables at a temperature T.
   * The averages are updated incrementally by summing the current values of the
   * observables. The true averages are computed during the saving step by
   * dividing this cumulative sum by the number of accumulated terms (mcs_av).
   */
  void updateModelAverages();

  /**
   * @brief Save the computed averages of the observables at a given
   * temperature.
   *
   * Computes the final averages by normalizing the accumulated sum of
   * observables over the specified number of Monte Carlo updates (mcs_av) and
   * saves the results to the subdirectory `average_output/averages`.
   *
   * @param[in] T Temperature at which the averages were computed.
   * @param[in] mcs_av Number of Monte Carlo updates over which the observables
   * were averaged.
   * @param[in] average_output Path to the folder where the averages will be
   * saved.
   */
  void saveModelAverages(double T, int mcs_av,const std::string &average_output);
};

} // namespace abstract_model_space

#endif // MODEL_HEADER_H
