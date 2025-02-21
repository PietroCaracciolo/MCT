# Build your model

Defining **your model** is the only coding required. The model's implementation resides in the `model` directory, structured with header files in `include` and source files in `src`.

Each model consists of five key components:

## 1. Parameters

The `parameters.h` header defines the structure and functions for managing **model parameters** and **simulation options**. It enables flexible configuration through an input file, allowing easy customization of the simulation setup. The header provides functions to parse parameters from a JSON file, store them in a structured format, and print them for verification. The implementation can be found in the `parameters.cpp` source file.
( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/Parameters.md) )

## 2. Interactions

The `interactions.h` header defines the structure and functions for managing the **model's energetics**. It provides a flexible approach for initializing and storing energetic data, with options to load from a file or use random initialization. The header includes functionality for initializing the model energetics, storing the information in a structured format, and printing the energetics details for verification. The implementation can be found in the `interactions.cpp` source file.

( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/Interactions.md) )

## 3. State

The `state.h` header defines the structures and functions for managing the **model's configuration** and **related observables** (e.g., total energy, magnetization for a spin system). It provides a flexible framework for initializing, storing, and manipulating the system's state. The header includes functionality for initializing the state, computing and printing the total energy, saving the configuration, and displaying the state details for verification. The implementation can be found in the `state.cpp` source file.

( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/State.md) )

## 4 .Update

The `update.h` header defines the functions required to perform **Monte Carlo update on the system**. It includes a method to update the system's configuration using the Metropolis algorithm, considering the energetics and update options defined in the parameters. The header provides the necessary functionality to modify the system's state based on the current configuration and simulation settings. The implementation can be found in the `update.cpp` source file.

( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/Update.md) )

## 5 .Averages

The `averages.h` header defines the structures and functions for managing the averages of the model's observables during the simulation, this includes for example the average of the total energy and of its higher powers. It provides functionality for initializing, updating, and saving statistical averages . The header also allows for creating output files to store these averages, ensuring that only the averages specified from the simulation parameters are calculated. The implementation can be found in the `averages.cpp` source file.

( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/Averages.md) )

### Additional Headers

Two additional headers are included to maintain the code's modularity and cleanliness:

### **Libraries**

The `libraries.h` header includes all necessary external libraries, such as `iostream`, ensuring that the code remains organized and dependencies are centrally managed.

( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/Libraries.md) )

### **Utils**

The `utils.h` header contains a set of  inline utility functions to help keep the code clean and efficient. This includes pre-written functions like exception handling, random number generation and vector printing, which are essential for the proper operation of the template.

( for practical informations on how to implement the parameters see : [What's already coded?](./implementation_guide/Utils.md) )

## Next Steps

Once your model is fully implemented, the next step is to **create the necessary input files**. For detailed instructions on how to write them, refer to [How to write your input files](./Write_input_files.md).
