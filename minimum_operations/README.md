# Minimum Operations

## Description

This project implements an algorithm to determine the minimum number of operations needed to produce exactly `n` characters `H` in a text file. Starting with a single `H`, the only allowed operations are:

- **Copy All**
- **Paste**

The goal is to reach `n` characters using the fewest steps possible.

## Implementation Details

- The function `minOperations(n)` calculates the minimum number of operations needed.
- The strategy is based on **prime factorization**: for each factor of `n`, the value of the factor is added to the operation count.
- Each factor represents a sequence of operations:
  - One `Copy All`
  - Followed by multiple `Paste`
- The function returns `0` if `n` is less than 2, since no operations are needed to build up 0 or 1 character.

## Files

- `0-minoperations.py`: Contains the `minOperations` function to solve the problem.
- `0-main.py`: A script that imports and tests the `minOperations` function with sample values of `n`.
- `README.md`: Documentation for the project.

## Compilation and Execution

To run the program, execute `0-main.py`, which tests the `minOperations` function with different inputs.

```bash
python3 0-main.py
```

## Example

Given the input:

```python
n = 4
```

The function `minOperations(n)` will return `4` because the optimal sequence is:

- Copy All → Paste (2)
- Copy All → Paste (4) → Total of 4 operations.

```python
n = 12
```

For this input, `minOperations(n)` will return `7` because:

- 12 = 2 × 2 × 3 → operations = 2 + 2 + 3 = 7

### Example run (from `0-main.py`)

```bash
$ python3 0-main.py
Min # of operations to reach 4 char: 4
Min # of operations to reach 12 char: 7
```

The script `0-main.py` runs the `minOperations` function on test values and prints the minimum number of operations required for each.
