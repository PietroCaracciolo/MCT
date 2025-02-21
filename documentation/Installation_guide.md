# Installation Guide

This guide will walk you through setting up the MCT repository, installing dependencies, and running a test simulation to verify the installation.

## 1. Clone the MCT Repository

First, clone the MCT repository using SSH. If you haven’t set up an SSH connection with GitHub, follow the instructions in [Setting up SSH](./Setting_up_SSH.md).

Navigate to your preferred directory and run:

```bash
git clone git@github.com:PietroCaracciolo/MCT.git
```

Verify the repository was cloned successfully:

```bash
ls
```

You should see the `MCT` directory.

## 2. Install Dependencies

Ensure all required dependencies for C++ and Python are installed (for the full list of requirements see [Requirements](./Requirements.md)). 

To automatically install all python requirements, run:

```bash
pip install -r requirements.txt
```

## 3. Compile the Executable

Once dependencies are installed, compile the executable:

```bash
make
```

This will create a `build` directory and generate an executable named `executable.exe`. You may see warnings like:

```bash
model/src/interactions.cpp:11:48: warning: unused parameter 'interactions' [-Wunused-parameter]
```

These are expected, as the template does not implement a specific model. They will disappear once you define your model.

## 4. Run a Test Simulation

To verify the setup, run a test simulation using the provided template input file `test` located in the `input` directory. Run:

```bash
./executable.exe test 0
```

Expected output:

```bash
[main] Input folder: test/0/
[Parameters]: Parameters successfully parsed
[Interactions]: Energetics initialization 'file'.
[Interactions]: Interactions initialized successfully.
[State]: Configuration initialization 'file'.
[State]: Initializing total energy.
[State]: State successfully initialized.
...
[Averages]: Save averages.
Energy at T = 20:
Total energy: 0
[Update]: updating the model configuration.
[Averages]: Initialize averages.
[Averages]: Update averages.
[Averages]: Save averages.
Energy at T = 0.141421:
Total energy: 0
[State]: Saving configuration to file.
```

A new directory `results/test/0` should now contain the test results.

### Next Steps

Congratulations! You have successfully installed MCT. You can now start building your model—see [How to Build Your Model](./Build_your_model.md) for details.
