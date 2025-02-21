# What's already coded?

In the model implementation, the **utils** module provides a collection of utility functions that aid in various tasks such as exception handling, random number generation, file I/O, and saving averages to files. These functions are designed to be used throughout the model and simplify common operations.

# Exception Handling

```cpp
inline void handleExceptions(const std::function<void()> &action, const std::string &context) 
```

A function that wraps code in a try-catch block to handle exceptions in a consistent manner, ensuring that any runtime or parsing errors are caught and properly reported.

# Generation of random numbers

```cpp
inline std::mt19937& rng() 
```

Provides access to a globally initialized random number generator (RNG). This RNG is based on the Mersenne Twister algorithm and is used to ensure consistent and efficient random number generation across the program.

```cpp
inline double randomDouble()
```

A function that generates a random double between 0 and 1 using the globally initialized RNG. Useful for **acceptance probabilities**.

# Saving scalars to a file

```cpp
inline void saveScalarAverageToFile(std::string file_name, double value, double T, int mcs_av, const std::string &context) 
```

This function is used to save the average value of scalar observables (like energy) to a file. The function takes the observable value, the temperature, the number of Monte Carlo steps, and a context string, and appends the average to the specified file.

# Creating files

```cpp
inline void createFile(std::string file_name, const std::string &context) 
```

A simple utility to create a file at the given path. It ensures that the file is successfully created and throws an error if the file cannot be opened.



# All utils are inline functions

All functions in the `utils` module are defined as **inline** functions within the header file. This means that the function definitions are provided directly in the header file, rather than in a separate source file (.cpp). In general, the decision to make these functions inline is a tradeoff between performance and potential code duplication. In this case, the functions are small and frequently called, so making them inline is beneficial for performance while ensuring the code remains easy to manage.

([Back to code your model](../Build_your_model.md))
