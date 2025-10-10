# Palindrome Integer

## Description

This project consists of a C function that determines whether a given unsigned long integer is a palindrome. An integer is considered a palindrome if it reads the same forwards and backward. For example, 121 is a palindrome, while 123 is not.

## Implementation Details

The core of the project is the `is_palindrome` function. It checks if a number is a palindrome without using dynamic memory allocation.

### Algorithm

The function implements a mathematical approach to reverse the integer:

1. A copy of the original number `n` is created to be modified.
2. A `reversed` variable is initialized to 0.
3. The function iterates through the copied number, extracting the last digit using the modulo operator (`% 10`).
4. This last digit is then appended to the `reversed` number.
5. The last digit is removed from the copied number using integer division (`/ 10`).
6. This process continues until the copied number becomes 0.
7. Finally, the original number `n` is compared to the `reversed` number. If they are identical, the number is a palindrome.

## Files

### `palindrome.h`

This is the header file that contains the function prototype for `is_palindrome` and all necessary includes for the project.

### `0-is_palindrome.c`

This file contains the implementation of the function:

- `is_palindrome(unsigned long n)`: Checks if the unsigned long `n` is a palindrome. It returns `1` if it is, and `0` otherwise.

## Compilation

The code is compiled using `gcc` with the following flags:

```bash
gcc -Wall -Wextra -Werror -pedantic -g3 0-main.c 0-is_palindrome.c -o palindrome
```

## Usage

To run the program, compile the files and execute the output with an unsigned integer as an argument:

```bash
./palindrome 12321
12321 is a palindrome.

./palindrome 12345
12345 is not a palindrome.
```
