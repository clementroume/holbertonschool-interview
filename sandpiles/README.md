# Sandpiles

## Description

This project implements the **sandpile model**, a mathematical concept used
to model **self-organized criticality**. A **sandpile** is represented as a
3x3 grid of integers, where each cell holds a number of grains of sand.

When a cell contains **more than 3 grains**, it **topples**, distributing
one grain to each of its adjacent cells (up, down, left, right). This process
continues until all cells have **at most 3 grains**, resulting in a stable
sandpile.

## Implementation Details

The program provides functions to **add two sandpiles** and ensure the result
is stable by toppling unstable cells iteratively.

### Toppling Rules

- If a cell contains more than 3 grains, it loses **4 grains**.
- Each of its **adjacent** cells receives **1 grain**.
- The process repeats until the grid is stable.

## Files

### `sandpiles.h`

Contains function prototypes and necessary includes.

### `sandpiles.c`

Implements the sandpile operations:

- `sandpiles_sum(grid1, grid2)`: Adds two sandpiles and stabilizes the result.
- `topple(grid1)`: Performs a single toppling iteration.
- `print_grid(grid)`: Prints a 3x3 sandpile.
- `is_stable(grid)`: Checks if a sandpile is stable.

## Compilation and Execution

To compile the program, use:

```sh
gcc -Wall -Wextra -Werror -pedantic *.c -o sandpiles
