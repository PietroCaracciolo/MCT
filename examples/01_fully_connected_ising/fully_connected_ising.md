# Example - Fully Connected Ising Model

The Fully Connected Ising Model is a classic statistical mechanics model that explores spin interactions on a fully connected lattice; in this setup, each spin interacts with every other spin. Due to its exact solvability, this model provides an excellent benchmark for validating numerical simulations.

## 1. Parameters

This model includes the following parameters:

- **$N$**: The total number of nodes.

- **interactions_initialization**: Specifies how the interaction strength is initialized (`random` or `file`).

- **state_initialization**: Specifies how the initial spin configuration is set (`random` or `file`).

- **save_E**: Boolean flag to track \langle E \rangle as a function of temperature.

- **save_E2**: Boolean flag to track \langle E^2 \rangle as a function of temperature.

- **save_E4**: Boolean flag to track \langle E^4 \rangle as a function of temperature.

- **save_m**: Boolean flag to track magnetization m as a function of temperature.

## 2. Interactions

The energetics parameters are: 

- **$J$**: Defines the interaction strength between the two spins. (negative for ferromagnetic interactions).

## 3. State

The system state is characterized by:

- **spin_config**: $\sigma = \{\sigma_i\}$ where each $\sigma_i = \pm 1$ represents a spin.

- **total energy**: Given by $E = \sum_{i,j} J S_i S_j$.

## 4. Update

One Monte Carlo step consists in a single-spin flip. A spin $i$ is chosen at random and flipped. One full update consists in $N$ Monte Carlo steps.

## 5 .Averages

### The following quantities are measured:

- **average_energy**: Computes $\langle E \rangle$ at a given temperature $T$.

- **average_energy2**: Computes $\langle E^2 \rangle$ at temperature $T$.

- **average_energy4**: Computes $\langle E^4 \rangle$ at temperature $T$.

- **average_m**: Computes the magnetization $m$.
