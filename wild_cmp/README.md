# Wild Compare

## Description

This project involves implementing a function that compares two strings and determines if they can be considered identical. The special feature is that the second string can contain the `*` character, which can act as a wildcard and match any string (including an empty string).

A major constraint of this project is the prohibition of loops (`for`, `while`, etc.), which requires a **recursive** approach to solve the problem.

## Implementation Details

- The function `int wildcmp(char *s1, char *s2)` compares the two strings.
- The logic is based entirely on recursion to traverse the strings.
- **Base Cases:** The recursion stops when the end of both strings is reached, returning `1`. If one string ends while the other still has characters (that are not `*`), it returns `0`.
- **Standard Comparison:** If the current characters are identical, the function recursively calls itself on the next characters (`s1 + 1`, `s2 + 1`).
- **Wildcard `*` Logic:**
  - When a `*` is encountered in `s2`, two possibilities are explored:
        1. The `*` matches an empty string: we ignore the `*` and continue the comparison by advancing in `s2`(`wildcmp(s1, s2 + 1)`).
        2. The `*` matches one or more characters: we advance in `s1` while staying on the same `*` in `s2`(`wildcmp(s1 + 1, s2)`).
  - If either of these recursive branches returns `1`, the strings match.
- Consecutive `*` characters are handled by effectively treating them as a single `*`.

## Files

- `0-wildcmp.c`: Contains the implementation of the `wildcmp` function.
- `holberton.h`: Header file containing the function prototype.
- `0-main.c`: An example script to test the `wildcmp` function.
- `README.md`: The documentation for the project.

## Compilation and Execution

To compile the program:

``` bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

To run the program:

``` bash
./0-wildcmp
```

## Example

Given the strings `s1 = "main.c"` and `s2 = "*.c"`, the `wildcmp` function will return `1` because `*` can replace "main.".

For `s1 = "main.c"` and `s2 = "m*c"`, the function will return `1` because `*` can replace "ain.".

For `s1 = "main.c"` and `s2 = "m.*c"`, the function will return `0` because the `.` is not a special character in this context and does not match the `a` in "main.c".

### Example Output (`0-main.c`)

``` bash
$ ./0-wildcmp
1
1
1
1
1
1
1
0
1
1
0
0
```

The `0-main.c` script runs the `wildcmp` function on several test cases, printing `1` if the strings are considered identical, and `0` otherwise.
