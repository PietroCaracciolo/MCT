# Writing input files

## 1. Directory Structure for Input Files

All simulation input files are stored in the `input` folder, which groups simulations by a **base name** and unique **simulation ID**. The `results` folder mirrors this structure, storing the corresponding output data for each simulation.

Simulations are grouped as follows:

1. **Simulation Name**: Each set of simulations is organized under a base name. This could represent for example different parameter sets (e.g., `parameters_1`, `parameters_2`, etc.).
2. **Simulation ID**: Within each base name, simulations are further organized by unique IDs (e.g., `1`, `2`, etc.).

This structure allows you to run multiple realizations of the same model with identical parameters, ensuring that each simulation is properly tracked while maintaining a shared configuration across all realizations.

Example folder structure:

```Example
input/
 ├── parameters_1/
 │    ├── simulation_0/
 │    └── simulation_1/
 └── parameters_2/
      ├── simulation_0/
      └── simulation_1/
```

Each subdirectory corresponds to a unique simulation ID and stores the relevant input files for that specific simulation.

## 2. Writing input files for a single simulation

Each simulation requires two input files: `model_params.json` and `mc_params.json`. To simplify their creation, a Jupyter notebook (`CreateInputs.ipynb`) is provided. This notebook allows you to generate and store the input files directly in the appropriate input directory, ensuring consistency and minimizing errors.

These files define all necessary parameters for running a simulation:

### Model parameters (`model_params.json`)

This file defines parameters that configure the model and simulation options, including initialization methods and observables to track.

Key parameters include:

- **Model definition Parameters**: These parameters define key characteristics of the model, such as the system size, whether the model is lattice-based or continuous, the type of degrees of freedom (e.g., Ising spins, Potts colors, lattice particles), and any other factors essential for defining the model's properties.
- **Initialization Options**: Define how interactions and the state are initialized (e.g., random initialization or loading from a file).
- **Average Options**: Boolean flags to select which observables are tracked over temperature, controlling result granularity.

Overall, this structure is essential for customizing the model setup and controlling the outputs during the simulation process.

### Monte Carlo parameters (`mc_params.json`)

This file configures the Monte Carlo engine, specifying temperature settings, update rules, cooling schedules, and output options.

The parameter file includes:

- **Temperature Settings**: Defines the initial and final temperatures, as well as the number of intermediate temperature steps used in the simulation.
- **Monte Carlo Steps**: Specifies the number of updates for system equilibration and observable averaging at each temperature.
- **Cooling Schedule**: Determines the spacing of temperature steps (e.g., linearly or exponentially).
- **Simulation Output**: Options for saving system configurations, defining simulation name and ID.

This structured format allows consistent and reproducible simulations while enabling customization based on the user's needs.

#### Additional Input Files

Additional input files can define model interactions or specify initial configurations from a file (see `example/fully_connected_ising`).

Congrats! Now everything is ready to run your simulation, see [3. Run your simulations](../README.md) for more details.
