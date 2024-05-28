# Prografo

The **Prografo** is a software tool designed to find maximum independent sets in a graph using various algorithms. It provides options to find maximum independent sets and maximal independent sets, and it can read graph input in DIMACS format.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [How to Compile](#how-to-compile)
- [Graph Input Format](#graph-input-format)
- [Algorithms](#algorithms)
- [Contributing](#contributing)
- [License](#license)

## Installation

To use the **Prografo**, you need to have a C compiler installed on your system. Additionally, this software depends on the **CLIQUE** library for some of its functionalities. You can find the **CLIQUE** library on [GitHub](https://github.com/danuta82/cliquer).

You can compile the software as described in the [How to Compile](#how-to-compile) section.

## Usage

The **Prografo** provides the following command-line options:

- `-a`: Find a maximum independent set.
- `-b`: Find all maximal independent sets.
- `-c`: Find all maximal independent sets and print them.

## How to Compile

To compile the Prografo, you can use the Makefile command:

```shell
make
```

This command assumes that you have the C compiler (GCC) and the C++ compiler (C++) installed on your system.

After compile, you can use:

```shell
make clean 
```

This command will remove the .o files.

## Graph Input Format

The software expects the input graph to be in DIMACS format. DIMACS format is a widely used text-based format for representing graphs with vertices and edges. You can find more information about DIMACS format [here](http://www.diag.uniroma1.it/challenge9/format.shtml).

## Algorithms

The Prografo uses recursive algorithms to find independent sets in the input graph. It can find maximum independent sets and maximal independent sets. The software also provides options to print the results.

## Contributing

Contributions to the Prografo are welcome. If you have any bug fixes, enhancements, or new features to propose, please open an issue or submit a pull request on the GitHub repository.

## License

Until this moment, Prografo is not a licensed software.