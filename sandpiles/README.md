# Sandpiles

## Description

This project implements the **sandpile model**, a mathematical concept
used to model **self-organized criticality**. A **sandpile** is represented
as a 3x3 grid of integers, where each cell holds a number of grains of sand.

When a cell contains **more than 3 grains**, it **topples**, distributing
one grain to each of its adjacent cells (up, down, left, right). This
process continues until the grid becomes **stable**.

## Implementation Details

The program provides functions to **add two sandpiles** and ensure the
result is stable by toppling unstable cells iteratively.

### Toppling Rules

- If a cell contains more than 3 grains, it loses **4 grains**.
- Each of its **adjacent** cells receives **1 grain**.
- The process repeats until all cells contain at most **3 grains**.

## Files

### `sandpiles.h`

Contains function prototypes and necessary includes.

### `0-sandpiles.c`

Implements the sandpile operations:

- `sandpiles_sum(grid1, grid2)`: Adds two sandpiles and stabilizes the result.
- `topple(grid1)`: Performs a single toppling iteration.
- `print_grid(grid)`: Prints a 3x3 sandpile.
- `is_stable(grid)`: Checks if a sandpile is stable.

### `0-main.c`

Provides two test case to demonstrate the sandpile operations.

## Compilation and Execution

To compile the program, use:

```sh
gcc -Wall -Wextra -Werror -pedantic *.c -o sandpiles
```

Run the executable:

```sh
./sandpiles
```

## Example

### Input (`0-main.c`):

```c
int grid1[3][3] = {
    {3, 3, 3},
    {3, 3, 3},
    {3, 3, 3}};

int grid2[3][3] = {
    {1, 3, 1},
    {3, 3, 3},
    {1, 3, 1}};

print_grid_sum(grid1, grid2);
sandpiles_sum(grid1, grid2);
printf("=\n");
print_grid(grid1);
```


### Output:

```sh
First Grid Sum:
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

## References

 [Abelian Sandpile Model](https://en.wikipedia.org/wiki/Abelian_sandpile_model)