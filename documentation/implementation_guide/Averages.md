# What's already coded?

In the model implementation, the **averages** module provides the functionality to calculate, update, and save the averages of important observables during the simulation. The main goal is to track and store observable averages. The module includes a structure to store these averages and several functions to manage their calculation and saving.

##### Don't worry about the energy!

The code to keep track of  energy-related observables (such as the average energy, average energy squared, and average energy to the fourth power) are already implemented, as these are popular and commonly tracked observables in many models. However, any model-specific averages can be added easily. The existing code for handling energy averages can serve as a template for incorporating additional observables. By following a similar structure, new averages can be tracked and saved efficiently.

If you need to add other observables, such as magnetization, order parameters, or specific correlations, you can adapt the existing `updateAverages` and `saveAverages` functions to accommodate these new quantities. Simply add the new averages to the `AveragesStruct` and implement the corresponding updates and saving logic, similar to the handling of energy averages.

# Average structure

The **AveragesStruct** structure holds all the necessary averages and the flag for controlling file creation. By default, it includes the following averages:

- **`_average_energy`**: The average energy of the system.

- **`_average_energy2`**: The average of the square of the energy.

- **`_average_energy4`**: The average of the fourth power of the energy.

Additionally, there is a flag to control file creation:

- **`_create_files`**: A boolean flag to indicate whether the output files for the averages should be created, `true` at the beginning of the run. Once the files are created, this flag is set to `false` for the rest of the simulatiuon.

# **Initializing the averages**

```cpp
void initializeAverages(AveragesStruct &averages, ModelParametersStruct &parameters, const std::string &average_output);
```

This function initializes the averages structure by setting all averages to zero and creating the necessary output files if they don’t exist. It uses the model parameters to determine which averages should be calculated. 

# Updating the averags

```cpp
void updateAverages(AveragesStruct &averages, StateStruct &state, ModelParametersStruct &parameters);
```

This function updates the averages using the current state of the system. It adds the current values of observables (e.g., energy) to the corresponding averages. The true averages will be calculated later during the saving step.

# Saving the averages

```cpp
void saveAverages(AveragesStruct &averages, ModelParametersStruct &parameters, double T, int mcs_av, const std::string &average_output);
```

This function saves the averages to files. It divides the accumulated sums by the number of terms (Monte Carlo steps, `mcs_av`) to compute the true averages. These averages are then saved to files for later analysis.

# Create files to store the averages

```cpp
void createFiles(ModelParametersStruct& parameters, const std::string &average_output);
```

This function creates the necessary files for storing the averages if they haven't been created yet. It is called during initialization to set up the file structure for storing the results.

([Back to code your model](../Build_your_model.md))
