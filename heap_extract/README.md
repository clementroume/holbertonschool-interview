# Heap Extract

## Description

This project involves implementing a function that extracts the root node of a Max Binary Heap. The operation must not only remove the largest value (the root) but also reorganize the heap to maintain its properties.

## Implementation Details

The `int heap_extract(heap_t **root)` function is at the core of this project. Its purpose is to extract and return the value of the root node while preserving the heap's integrity.

Here is how it works:

1. **Save the Value**: The value of the root node is stored to be returned at the end.
2. **Replace the Root**: The root is replaced with the last node in the level-order traversal.
3. **Free Memory**: The original root node is freed.
4. **Heapify Down**: After the replacement, the new root element is "sifted down" to ensure the Max Heap property is respected. This means it is swapped with its largest child until it is larger than both its children.
5. **Error Handling**: The function returns `0` if the heap is empty or if an error occurs.

## Files

- `0-heap_extract.c`: Contains the implementation of the `heap_extract` function.
- `binary_trees.h`: The header file containing structure definitions and function prototypes.

## Compilation & Execution

The project is compiled with `gcc` using the `-Wall -Werror -Wextra -pedantic` flags. The provided `main.c` file is used to test the function.

``` bash
gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
```

To run the test program:

``` bash
./0-heap_extract
```

## Example

Starting with a Max Binary Heap, the `heap_extract` function is called multiple times. With each call, the largest element is extracted, and the heap is readjusted.

``` bash
# Initial Heap
                      .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)

# After the first extraction
Extracted: 98
                 .-----------------(095)-----------------.
       .-------(084)-------.                   .-------(091)-------.
  .--(047)--.         .--(079)--.         .--(087)--.         .--(062)--.
(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)

# After the second extraction
Extracted: 95
                 .-----------------(091)-----------------.
       .-------(084)-------.                   .-------(087)-------.
  .--(047)--.         .--(079)--.         .--(068)--.         .--(062)
(032)     (034)     (002)     (020)     (022)     (021)     (001)
```
