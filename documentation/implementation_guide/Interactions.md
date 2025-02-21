# What's already coded?

In the model implementation, code for managing the model's energetics (interactions) is provided. This part of the code allows you to initialize and print the energetic properties of the model. Specifically, it includes the definition of an `InteractionStruct` to hold the energetic information, as well as functions to initialize and print the interactions based on the configuration set in the model parameters.

# Interactions Structure

The `InteractionStruct` structure is designed to store the energetic information required for the model. At this stage, it is an empty structure, but it will hold the interactions once implemented.

# Initializing model energetics

```cpp
void initializeInteractions(InteractionStruct &interactions, ModelParametersStruct &parameters, const std::string &input_folder);
```

This function initializes the model's energetics according to the configuration provided in the `ModelParametersStruct`. It supports two initialization options:

- **"random"**: Randomly initializes the energetics.

- **"file"**: Loads the energetics from a JSON file (i.e., `interactions.json`) located in the specified input folder.

The function checks the initialization option and performs the appropriate action. If the "file" option is selected, it attempts to load the interactions from the provided file path.

These two options can serve as templates for adding more initialization methods in the future, making it easy to extend the model with additional ways to initialize the energetics (e.g., from a different file format, or using a specific algorithm).

# Printing model energetics



```cpp
void printInteractions(InteractionStruct &interactions);
```



This function prints a summary of the energetics stored in the `InteractionStruct`. While the structure itself is currently empty, this function will provide an overview of the energetics once it is implemented.

([Back to code your model](../Build_your_model.md))
