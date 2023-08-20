# Pipex Project

Pipex is a command-line utility that simulates the behavior of the shell pipeline in Unix-like operating systems. It allows you to redirect the standard input and output of commands, similar to how the `|` operator works in the shell.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Pipex is designed to help you understand and practice how the shell processes pipelines of commands. It provides a way to redirect the input and output of a sequence of commands, just like how it is done using the shell's pipe operator (`|`). This project is developed as part of the educational experience and is not intended to replace actual shell functionality.

## Features

- Simulate shell pipeline behavior.
- Redirect input and output for each command.
- Error handling for invalid inputs.
- Easy-to-use command-line interface.

## Usage

The basic syntax for using Pipex is as follows:

```sh
./pipex file1 cmd1 cmd2 file2
```

- `file1`: The input file.
- `cmd1`: The first shell command.
- `cmd2`: The second shell command.
- `file2`: The output file.

## Installation

### Prerequisites

Before installing Pipex, make sure you have the following tools installed on your system:

- `gcc` (GNU Compiler Collection)
- `make` (Build automation tool)

### Steps

To install Pipex, follow these steps:

1. Clone this repository:

```
git clone git@github.com:armanmartirosyan/pipex.git
```

2. Navigate to the project directory:

```
cd pipex
```

3. Build the executable using the provided Makefile:

```
make
```

This will allow you to use the `./pipex` command.

## Contributing

Contributions are welcome! If you find any bugs or want to improve the functionality of Pipex, please open an issue or submit a pull request. Make sure to follow the project's code of conduct.

## License

This project is licensed under the [MIT License](LICENSE).
