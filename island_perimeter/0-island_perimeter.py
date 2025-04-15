#!/usr/bin/python3
"""
island_perimeter - Returns the perimeter of the island described in a grid.
@grid: List of List of integers where:
    0 represents water,
    1 represents land.
Returns the perimeter of the island described in grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    perimeter = 0

    # Iterate through each cell in the grid
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perimeter += 4  # Each land cell adds 4 to the perimeter

                # Check the neighboring land cells and reduce
                # perimeter accordingly
                if row > 0 and grid[row - 1][col] == 1:  # Check above
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:  # Check left
                    perimeter -= 2

    return perimeter
