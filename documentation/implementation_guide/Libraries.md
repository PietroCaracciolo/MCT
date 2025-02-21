# What's already coded?

In the project, the **`libraries.h`** header is used to centralize the inclusion of all external libraries. This approach simplifies dependency management and ensures consistency across the entire project. By including this header in other modules, the necessary libraries are easily accessible without the need to repeatedly include them in each individual file.

# Libraries Included

The **`libraries.h`** header includes several external libraries that are commonly used throughout the project:

- **`<fstream>`**: Provides functionality for file input and output operations.

- **`<iostream>`**: Provides functionality for input and output stream operations.

- **`<json.hpp>`**: The header-only JSON library from `nlohmann::json` for easy parsing and manipulation of JSON data.

- **`<random>`**: Contains random number generation facilities for creating random numbers using different distributions.

# Aliases

- **`json`**: The `nlohmann::json` library is aliased as `json` for convenience, simplifying its usage across the project.

([Back to code your model](../Build_your_model.md))
