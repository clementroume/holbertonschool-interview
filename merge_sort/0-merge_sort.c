#include "sort.h"

/**
 * merge - Merge two sorted subarrays into a single sorted array.
 * @array: the array to sort.
 * @tmp: temporary array for merging.
 * @left: left index of subarray.
 * @mid: middle index.
 * @right: right index of subarray.
 */
static void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	while (i <= mid)
		tmp[k++] = array[i++];
	while (j <= right)
		tmp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_rec - Recursive merge sort helper.
 * @array: array to sort.
 * @tmp: temporary array.
 * @left: left index.
 * @right: right index.
 */
static void merge_sort_rec(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (left >= right)
	{
		return;
	}

	mid = left + (right - left - 1) / 2;

	merge_sort_rec(array, tmp, left, mid);
	merge_sort_rec(array, tmp, mid + 1, right);
	merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: array to sort.
 * @size: number of elements in array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
	{
		return;
	}

	tmp = malloc(sizeof(int) * size);

	if (!tmp)
		return;

	merge_sort_rec(array, tmp, 0, size - 1);

	free(tmp);
}
