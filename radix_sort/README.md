# Radix Sort

## Description

This project implements the **Radix Sort** algorithm to sort an array of integers in ascending order. The implemented algorithm is the **LSD (Least Significant Digit)** variant, which sorts numbers based on their digits, starting from the least significant digit and moving to the most significant

## Implementation Details

- The function `void radix_sort(int *array, size_t size)` sorts the array of integers.
- The algorithm first determines the largest number in the array to find the maximum number of digits.
- It uses a stable sorting approach (similar to counting sort) to sort the elements based on each digit (ones, tens, hundreds, etc.).
- The array is traversed and reorganized for each digit position, starting from the right (LSD).
- A project requirement is to print the array each time the significant digit used for sorting increases.

## Files

- `0-radix_sort.c`: Contains the implementation of the `radix_sort` function.
- `sort.h`: Header file containing the prototypes for all functions, including `radix_sort` and the provided `print_array` function.
- `0-main.c`: An example script to test the `radix_sort` function.
- `README.md`: The documentation for the project.

## Compilation and Execution

To compile the program:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-radix_sort.c print_array.c -o radix
```

To run the program:

```nash
./radix
```

## Example

Given the following input array:

```bash
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
```

The `radix_sort` function will sort the array. The output of the example program (`0-main.c`) will be:

```bash
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

- The first line is the unsorted array.
- The second line shows the array after sorting by the units digit (the least significant).
- The third line shows the array after sorting by the tens digit.
- The last line displays the final, fully sorted array.

---
