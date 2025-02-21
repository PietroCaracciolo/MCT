# **Requirements**

## C++ requirements

To compile this project, you need:

- **C++ Compiler**
  
  - GCC **7 or later** (Linux/macOS)
  - Clang **5 or later** (alternative)
  - MinGW-w64 **(for Windows users)**
  
  To check your compiler version, run:
  
  ```bash
  g++ --version
  ```

- **Make**
  
  - Standard on Linux/macOS
  - On Windows: Install **MinGW** or use **WSL (Windows Subsystem for Linux)**
  
  To check if you have Make, run:
  
  ```bash
  make --version
  ```

- **Required Libraries**
  
  - `nlohmann/json` → Already included in the project (**no installation needed**)

## Python Requirements

To work with the Python components of this project, ensure the following:

- **Python Version**: **3.11.7** 
  To verify your Python version, run the following command:
  
  ```bash
  python --version
  ```
  
  or, if using Python 3:
  
  ```bash
  python3 --version
  ```

- **Dependencies**:
  
  - `numpy` version **2.2.2**
    Install with: `pip install numpy==2.2.2` (or `pip3 install numpy==2.2.2`  for python3).
  
  - `json` – Included with the standard Python library (**no installation required**).
  
  - `os` – Included with the standard Python library (**no installation required**).
