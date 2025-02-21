# What's already coded?

In the model implementation, some code is already provided to handle common tasks for any type of model. One of these tasks is managing the model parameters and simulation options. The provided code defines a structure and functions for handling these parameters, which control the setup of the model and the execution of the simulation. This includes the definition of a `ModelParametersStruct` structure to store the configuration options, as well as functions to parse the parameters from a file and print them for verification.

# Parameters structure

The `ModelParametersStruct` structure holds the parameters that define the configuration and simulation options for the model. By default, it includes the following parameters:

- **`_interactions_initialization`**: Specifies how the model's energetics are initialized. ( The code by default allaws as possible options  `random` and `file`).

- **`_state_initialization`**: Specifies how the model's state is initialized. ( The code by default allaws as possible options `random` and `file`).

- **`_save_E`**: A flag to indicate whether the average energy should be saved. ( The code by default implements functions to save the average energy).

- **`_save_E2`**: A flag to indicate whether the average energy^2 should be saved. ( The code by default implements functions to save the average energy squared).

- **`_save_E4`**: A flag to indicate whether the average energy^4 should be saved. ( The code by default implements functions to save the  average energy ^ 4).

# Parsing model parameters from input file

```cpp
void parseParameters(ModelParametersStruct &parameters, const std::string &input_folder);
```

This function parses the JSON file (`model_params.json`) and populates the `ModelParametersStruct` structure with the values found in the file. It also checks that the initialization options (for both energetics and state) are valid, ensuring the correct configuration.

# Printing model parameters for debug

```cpp
void printParameters(ModelParametersStruct &parameters);
```

This function outputs the values of the parameters stored in the `ModelParametersStruct` structure, allowing you to check and confirm the current configuration.

([Back to code your model](../Build_your_model.md))
