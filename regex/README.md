# ReegEx

## Description

This project implements a C function capable of checking if a given string matches a regular expression pattern. The regex engine supports the basic operators `.` and `*`.

The `.` (dot) is a metacharacter that matches any single character.
The `*` (asterisk) is a quantifier that matches zero or more occurrences of the preceding element.

## Implementation Details

The program provides a function, `regex_match`, which recursively compares a string (`str`) to a pattern (`pattern`) to determine if they match.

### Matching Rules

- A standard character match occurs when the character in the string is identical to the one in the pattern.
- The `.` character in the pattern matches any single character in the string.
- The `*` character in the pattern indicates that the preceding element can appear zero or more times.
  - For example, `H*` matches "", "H", "HH", "HHH", etc.
  - `.*` matches any sequence of characters (including an empty sequence).

## Files

### `regex.h`

Contains the function prototype for the matching logic and necessary includes.

### `regex.c`

Implements the main matching logic function:

- `regex_match(str, pattern)`: Recursively compares the string `str` to the pattern `pattern` and returns 1 on match, 0 otherwise.

### `main.c`

Provides a series of test cases to demonstrate how `regex_match` works with various patterns.
