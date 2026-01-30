# Rain

## Description

This project implements an algorithm to solve the "trapping rain water" problem. Given a list of non-negative integers representing the heights of walls (viewed as a 2D cross-section), the function calculates the total volume of water that can be retained between the walls after a rainfall.

## Implementation Details

- The function `rain(walls)` calculates the total units of trapped water.
- The algorithm uses a **two-pass approach** to determine the water level at each position.
- **First Pass (Left to Right):** It computes an array `left_max`, where each element `left_max[i]` stores the height of the tallest wall to the left of and including index `i`.
- **Second Pass (Right to Left):** It computes another array `right_max`, where `right_max[i]` stores the height of the tallest wall to the right of and including index `i`.
- **Final Calculation:** The amount of water trapped above any given wall `walls[i]` is determined by the shorter of the two surrounding highest walls, calculated as `min(left_max[i], right_max[i]) - walls[i]`. The total is the sum of these values for all walls.

## Files

- `0-rain.py`: Contains the `rain` function that implements the solution.
- `0_main.py`: A script that imports and tests the `rain` function with different wall configurations.
- `README.md`: Documentation for the project.

## Execution

To run the program, you can execute the `0_main.py` script, which will test the `rain` function with various inputs and print the results.

```sh
./0_main.py
```

## Example

Given a list of walls represented as:

```sh
walls = [0, 1, 0, 2, 0, 3, 0, 4]
```

The function `rain(walls)` will return `6`, which is the total number of square units of water that can be trapped.

### Example run (from `0_main.py`)

```sh
$ ./0_main.py
6
6
```

The script `0_main.py` runs the `rain` function on multiple test cases, printing the total amount of water retained for each scenario.
