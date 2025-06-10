# MCT - Monte Carlo Template

Writing Monte Carlo simulations for user-defined models often leads to repetitive code, which can be error-prone and time-consuming. If you've written one of these simulations more than once, you’ve likely encountered the same mistakes and debugging hours, wasting precious research time on tasks that don’t contribute to the core of your project.

This project provides a fast, robust, and reusable C++ interface that automates common tasks in Monte Carlo simulations, streamlining the process and minimizing the need for redundant code. With this tool, you can focus on your research while the framework handles the rest. 

## 1. Code structure

The code is structured in two main parts: **the interface** which deal with the Monte Carlo simulation and is already fully implemented, and the **model** which instead is user implemented and deals with the specificities of each model. 

### The Monte Carlo Interface (`interface`)

This component is responsible for executing Monte Carlo simulations. It consists of two primary blocks: the **Abstract model** and the **Monte Carlo engine**. Both have been implemented, tested, and optimized for performance.

The **Abstract model** provides a general interface for modeling physical systems, specifying essential attributes and methods that all models must implement. By using static polymorphism, it ensures that the appropriate model is selected at compile time, eliminating any runtime overhead. This allows the Monte Carlo engine to integrate with any user-defined model within a consistent framework.

The **Monte Carlo engine** is a template class designed to interact with user-defined models. It carries out Monte Carlo Simulated Annealing using the Abstract model to manage the specific characteristics of any real model's specific details. The engine can run simulations at a fixed temperature or across a temperature range, enabling an effective exploration of phase space.

### The Model (`model`)

The **Model** component is where users will implement their specific model for the Monte Carlo simulation. The structure is already provided, with all necessary header and source files in place and thoroughly tested. Users simply need to complete these files with their model-specific details, following the guidelines given in Section 2. This involves defining the **Parameters**, **Interactions**, **State**, **Update**, and **Averages** sections, all of which are pre-structured to support the required functionalities. The provided framework allows users to focus on the unique aspects of their model while ensuring compatibility with the Monte Carlo Interface.

## 2. How do you simulate your model?

The process from installation to analyzing your simulation results involves three main steps: **installing the MCT repository**,  **building your model** and **writing input files**.

* [How to install MCT](./documentation/Installation_guide.md)

* [How to build your model](./documentation/Build_your_model.md)

* [How to write  your input files](./documentation/Write_input_files.md)

## 3.Run your simulation

Once your **implemented your model**, and **wrote the input files** you can run a simulation from terminal using the following command: 

```bash
./executable <simulation_name> <simulation_ID>
```

For example if your input files are stored in the folder `input/test/0` the command will be:

```bash
./executable test 0
```

## 4. Examples

The project includes some examples demonstrating the use of the Monte Carlo Template to implement real models. The simplest example is a [two spin system](./examples/00_two_spin_system/two_spin_system.md), while a more complex and realistic example features a [fully connected ising model](./examples/01_fully_connected_ising/fully_connected_ising.md). Detailed documentation for each example can be found in their respective directories, providing instructions and insights into how these models are implemented.

## License
This project is licensed under the BSD 3-Clause License - see the [LICENSE](./LICENSE) file for details.

### Acknowledgments
- This project utilizes parts of `frusa_mc`, developed by the **Soft Biophysics Group LPTMS**, and released under the BSD 3-Clause License.
- It also includes [`json`](https://github.com/nlohmann/json) by Niels Lohmann (MIT License).


### Contact
If you have any issues with the code please let me know by e-mail at: pietro.caraccioloditorella@gmail.com
