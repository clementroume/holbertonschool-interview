#include "slide_line.h"

/**
 * shift_left - Moves all non-zero values to the left side of the array.
 * @line: The array of integers.
 * @size: The size of the array.
 */
void shift_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
}

/**
 * slide_left - Shifts numbers to the left and merges identical ones.
 * @line: The array of integers.
 * @size: The size of the array.
 *
 * This function first shifts non-zero values to the left, then merges
 * consecutive identical values by doubling the leftmost one and setting
 * the right one to 0. After merging, another shift_left ensures consolidation.
 */
void slide_left(int *line, size_t size)
{
	size_t i;

	/* Initial shift to the left */
	shift_left(line, size);

	/* Merge identical values from left to right */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	/* Second shift to ensure proper positioning */
	shift_left(line, size);
}

/**
 * shift_right - Moves all non-zero values to the right side of the array.
 * @line: The array of integers.
 * @size: The size of the array.
 */
void shift_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i-- > 0;) /* Start from the rightmost index */
	{
		if (line[i] == 0)
		{
			for (j = i; j-- > 0;) /* Find the closest non-zero value to swap */
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
}

/**
 * slide_right - Shifts numbers to the right and merges identical ones.
 * @line: The array of integers.
 * @size: The size of the array.
 *
 * This function first shifts non-zero values to the right, then merges
 * consecutive identical values by doubling the rightmost one and setting
 * the left one to 0. After merging, another shift_right ensures consolidation.
 */
void slide_right(int *line, size_t size)
{
	size_t i;

	/* Initial shift to the right */
	shift_right(line, size);

	/* Merge identical values from right to left */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	/* Second shift to ensure proper positioning */
	shift_right(line, size);
}

/**
 * slide_line - Slides and merges numbers in a given direction.
 * @line: The array of integers.
 * @size: The size of the array.
 * @direction: The direction (0 for left, 1 for right).
 *
 * Return: 1 if operation is successful, 0 if invalid input.
 *
 * This function ensures all numbers are even before proceeding with
 * shifting and merging in the specified direction.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	/* Validate that all numbers are even */
	for (i = 0; i < size; i++)
	{
		if (line[i] % 2 != 0)
		{
			return (0);
		}
	}

	/* Perform the sliding operation based on the given direction */
	switch (direction)
	{
	case 0: /* Left */
		slide_left(line, size);
		break;

	case 1: /* Right */
		slide_right(line, size);
		break;

	default:
		return (0);
	}
	return (1);
}
