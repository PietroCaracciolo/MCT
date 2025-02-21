# Example - Two-Spin System

The system consists of two Ising spins ($S = \pm 1$) interacting based on their relative orientation. The total interaction energy is given by:

$E = \alpha \epsilon S_1 S_2$ 

Here, $\alpha$ determines the nature of the interaction ($\alpha = -1$ for ferromagnetic coupling and $\alpha = 1$ for antiferromagnetic coupling), and $\epsilon > 0 $ determines the strength of such interaction. 

## 1. Parameters

This model includes the following parameters:

- **alpha**: Defines the interaction type ($-1$ for ferromagnetic, $1$ for antiferromagnetic).

- **interactions_initialization**: Specifies how the interaction strength is initialized (`random` or `file`).

- **state_initialization**: Specifies how the initial spin configuration is set (`random` or `file`).

- **save_E**: Boolean flag to track $\langle E \rangle$ as a function of temperature.

- **save_E2**: Boolean flag to track $\langle E^2 \rangle$ as a function of temperature.

- **save_E4**: Boolean flag to track $\langle E^4 \rangle$ as a function of temperature.

- **save_m**: Boolean flag to track magnetization $m$ as a function of temperature.

## 2. Interactions

The interaction strength is governed by:

- **epsilon**: Defines the interaction strength between the two spins.

## 3. State

The system state is characterized by:

- **spin_config**: The configuration of the two spins, which can be one of four possible states: ($\uparrow \uparrow$), ($\downarrow \uparrow$), ($\uparrow \downarrow$), or ($\downarrow \downarrow$).

- **total energy**: Given by $E = \alpha \epsilon S_1 S_2$.

## 4. Update

Monte Carlo updates are performed via single-spin flips. For example, flipping $S_2$ changes the state:         $\uparrow \uparrow$   $\rightarrow$   $\uparrow \downarrow$ .

## 5. Averages

### The following quantities are measured:

- **average_energy**: Computes $\langle E \rangle$ at a given temperature $T$.

- **average_energy2**: Computes $\langle E^2 \rangle$ at temperature $T$.

- **average_energy4**: Computes $\langle E^4 \rangle$ at temperature $T$.

- **average_m**: Computes the magnetization $m$.
