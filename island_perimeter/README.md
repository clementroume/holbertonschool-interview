# Island Perimeter

## Description

This project implements an algorithm to calculate the perimeter of an island
described in a grid. The grid consists of land and water cells, where:

- `1` represents land,
- `0` represents water.

The algorithm calculates the perimeter of the island formed by `1` cells in the grid. Each land cell contributes 4 to the perimeter, and shared sides between adjacent land cells reduce the perimeter by 2 for each shared side.

## Implementation Details

- The function `island_perimeter(grid)` computes the perimeter of the island described in the grid.
- The grid is represented as a list of lists, where each sublist represents a row, and each integer represents either water (0) or land (1).
- The function iterates through each cell in the grid:
  - For every land cell (`1`), it adds 4 to the perimeter.
  - If a neighboring cell (above or to the left) is also land (`1`), the perimeter is reduced by 2 for each shared edge.
  
## Files

- `0-island_perimeter.py`: Contains the `island_perimeter` function to solve the problem.
- `0-main.py`: A script that imports and tests the `island_perimeter` function with different grid configurations.
- `README.md`: Documentation for the project.

## Compilation and Execution

To run the program, execute `0-main.py`, which tests the `island_perimeter` function with various inputs.

```bash
python3 0-main.py
````

## Example

Given a grid representing an island:

```python
grid = [[0, 0, 0, 0, 0, 0],
  [0, 1, 0, 0, 0, 0],
  [0, 1, 0, 0, 0, 0],
  [0, 1, 1, 1, 0, 0],
  [0, 0, 0, 0, 0, 0]]
```

The function `island_perimeter(grid)` will return `12` since the perimeter of the island formed by `1` cells is 12.

### Example run (from `0-main.py`)

```bash
$ python3 0-main.py
12
```

The script `0-main.py` runs the `island_perimeter` function on the grid and prints the perimeter of the island.

---
