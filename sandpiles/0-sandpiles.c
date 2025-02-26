#include "sandpiles.h"
#include <stdio.h>

/**
 * topple - Topples a sandpile grid if any cell has more than 3 grains of sand.
 * @grid1: The 3x3 grid representing the sandpile.
 *
 * Description: If a cell in grid1 has more than 3 grains, it topples by
 *              distributing 1 grain to each adjacent cell. Changes are stored
 *              in grid2 to prevent modifying grid1 during iteration. After
 *              processing all cells, grid1 is updated with grid2's values.
 */
void topple(int grid1[3][3])
{
	int i, j;
	int grid2[3][3];

	/* Initialize grid2 with zeros */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;

	/* Process each cell and distribute grains if unstable */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3) /* Unstable cell */
			{
				grid1[i][j] -= 4;
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
			}
		}
	}

	/* Apply the changes */
	sandpiles_sum(grid1, grid2);
}

/**
 * print_grid - Prints a 3x3 grid of integers.
 * @grid: The 3x3 grid to be printed.
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a sandpile is stable (no cell > 3).
 * @grid: The 3x3 grid to check.
 *
 * Return: 1 if stable, 0 otherwise.
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result.
 * @grid1: The first 3x3 grid representing a sandpile.
 * @grid2: The second 3x3 grid representing a sandpile.
 *
 * Description: Adds grid2 to grid1 element-wise and topples the grid until it
 *              becomes stable. Each unstable state is printed before toppling.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 element-wise */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	/* Stabilize the grid */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
