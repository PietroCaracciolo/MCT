# What's already coded?

In the model implementation, code to manage the system’s configuration (state) is provided. This section handles how the initial configuration is set up, the energy is computed, and the configuration is saved. Specifically, it defines a `StateStruct` to hold the configuration and energy data, and provides functions to initialize, print, and save the state of the model.

# State Structure

The `StateStruct` structure holds the configuration of the model. It contains the following data:

- **`_total_energy`**: The total energy of the current configuration. This is computed during initialization.

# Initializing model state

```cpp
void initializeState(StateStruct &state,InteractionStruct& interactions,ModelParametersStruct &parameters, const std::string &input_folder);
```

This function initializes the system’s state based on the configuration options provided in `ModelParametersStruct`. It supports two initialization options:

- **"random"**: Randomly initializes the configuration.

- **"file"**: Loads the configuration from a JSON file (`state.json`) located in the specified input folder.

This function computes the total energy of the configuration once it is initialized.

The two provided options (random and file) can serve as templates for adding more initialization methods, such as loading from a different format or using a specific algorithm.

# Printing model state

```cpp
void printState(StateStruct &state);
```

This function prints a summary of the current state. While it does not currently display much information, it will print details about the initial configuration once implemented.

# Saving model state

```cpp
void saveState(StateStruct &state, const std::string &state_output);
```

This function saves the current state to a file. The path to the output folder where the state will be saved is provided as an argument.

# Printing total energy

```cpp
void printEnergy(StateStruct &state);
```

This function prints the total energy of the system, as stored in the `StateStruct`.

# Computing total energy

```cpp
int computeTotalEnergy(StateStruct& state, ModelParametersStruct& parameters, InteractionStruct& interactions);
```

This function computes the total energy of the configuration. The actual energy calculation is not implemented yet, but it will use the configuration and interactions to compute and return the total energy.

([Back to code your model](../Build_your_model.md))
