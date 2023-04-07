## Brute Force Algorithm for Solving the Travelling Salesman Problem

This project is a C++ implementation of the brute force algorithm for solving the Travelling Salesman Problem (TSP). The TSP is an optimization problem of finding the minimum Hamiltonian cycle in a complete weighted graph.

## Build the project

Run:

```bash
make
```

## Define the algorithm settings:

- To change the algorithm settings, edit the [`settings.ini`](settings.ini) file.
- The settings file defines basic parameters of the algorithm as well as the instances which will be used by the algorithm.
- Example instance files are located in the [`instances`](instances) directory
- Instance files define the graphs on which the algorithm will be called. They can have two extensions:
  - `.tsp` for undirected graphs (e.g. [`gr17.tsp`](instances/gr17.tsp))
  - `.atsp` for directed graphs (e.g. [`m6.atsp`](instances/m6.atsp))

## Run the algorithm:

Run:

```bash
./bin/main
```

The results will be saved as `.csv` files in a directory defined in the `settings.ini` file.
