#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * find_max - Finds the maximum value in an array of integers.
 * @array: The array to search.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *array, size_t size)
{
	int max = 0;

	if (array && size > 0)
	{
		max = array[0];
		for (size_t i = 1; i < size; i++)
		{
			if (array[i] > max)
				max = array[i];
		}
	}
	return (max);
}

/**
 * radix_pass - Performs a single pass of counting sort for a specific digit.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current exponent (1, 10, 100...), representing the digit place.
 * @output: A temporary buffer to store the sorted array for this pass.
 */
void radix_pass(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};

	/* Store count of occurrences of each digit (0-9) */
	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so that it now contains the actual position */
	/* of this digit in the output array (cumulative count) */
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array by placing numbers in their correct sorted order. */
	/* We iterate backwards to ensure the sort is stable. */
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the sorted elements from the output array back to the original. */
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * LSD Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	/* An array of size less than 2 is already sorted */
	if (array == NULL || size < 2)
		return;
	/* Find the maximum number to know the number of digits */
	int max = find_max(array, size);
	/* Allocate memory for a temporary buffer once to improve performance */
	int *output = malloc(sizeof(int) * size);

	if (!output)
		return;

	/* Perform counting sort for every digit. The exponent (exp) is 10^i */
	/* where i is the current digit number (0, 1, 2...). */
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		radix_pass(array, size, exp, output);
		/* Print the array after each significant digit pass, as required */
		print_array(array, size);
	}
	/* Free the allocated memory */
	free(output);
}
