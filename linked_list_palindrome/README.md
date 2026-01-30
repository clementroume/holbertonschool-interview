# Linked List Palindrome

## Description

This project implements an algorithm to determine if a singly linked list is a palindrome. A palindrome is a sequence that reads the same backward as forward. The algorithm efficiently checks for this property by reversing the first half of the list while using two pointers (`slow` and `fast`) to identify the middle.

## Implementation Details

- The function `is_palindrome(listint_t **head)` checks if the linked list is a palindrome.
- The list is traversed using two pointers:
  - `fast` moves two steps at a time.
  - `slow` moves one step at a time.
- While traversing, the first half of the list is reversed.
- If the list has an odd number of elements, the middle node is skipped.
- The reversed first half is then compared with the second half of the list.
- If all corresponding nodes match, the list is a palindrome; otherwise, it is not.

## Files

- `palindrome_linked_list.c`: Contains the `is_palindrome` function.
- `lists.h`: Header file with the definition of the linked list structure.
- `main.c`: Script to test the `is_palindrome` function with different linked lists.
- `README.md`: Documentation for the project.

## Compilation and Execution

To compile the program:

```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 palindrome_linked_list.c main.c -o palindrome
```

To run the program:

```bash
./palindrome
```

## Example

Given a linked list represented as:

```c
1 -> 2 -> 2 -> 1
```

The function `is_palindrome` will return `1` since the list reads the same forwards and backwards.

For this input:

```c
1 -> 2 -> 3 -> 2 -> 1
```

`is_palindrome` will also return `1`.

For the list:

```c
1 -> 2 -> 3
```

`is_palindrome` will return `0`, as the list is not a palindrome.

### Example run (from `main.c`)

```c
$ ./palindrome
1
0
```

The script `main.c` runs the `is_palindrome` function on multiple test cases, printing whether the linked list is a palindrome for each case.
