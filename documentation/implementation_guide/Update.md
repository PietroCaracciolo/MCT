# What's already coded?

In the model implementation, a function to perform Monte Carlo updates is provided. This function modifies the system configuration using a Monte Carlo method, which is often used for simulating the thermodynamic behavior of systems. The function makes use of the model's current configuration and energetics and is flexible to accommodate various update options.

# Monte Carlo Update Function

```cpp
void updateSystem(StateStruct &state, InteractionStruct &interactions, ModelParametersStruct &parameters, double T);
```

This function updates the configuration of the system using the Monte Carlo method. It takes the following arguments:

- **`state`**: The current configuration of the system (as defined in `StateStruct`).

- **`interactions`**: The energetics of the system, which are used in the Metropolis acceptance criterion to decide whether to accept or reject the proposed configuration.

- **`parameters`**: Contains options related to the update process, such as which parts of the model to update or which type of Monte Carlo move to use (eg. normal moves or  cluster moves).

- **`T`**: The temperature parameter used in the Monte Carlo update. It typically influences the acceptance probability of new configurations.

At present, the function only outputs a debugging message indicating that the model configuration is being updated. However, it is designed to be extended to implement the actual Monte Carlo update logic. The function can be expanded by adding more update types, depending on the parameters passed.

([Back to code your model](../Build_your_model.md))
