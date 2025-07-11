# Making Change

## Description

This project addresses a classic algorithmic problem: determining the **minimum number** of coins needed to make a specific total amount. Given a list of available coin denominations, the goal is to find the most efficient combination to form the total.

---

## Implementation

The logic is contained in a single function, `def makeChange(coins, total)`.

- The algorithm uses a **dynamic programming** approach to find the optimal solution. It builds a solution by referencing the results of sub-problems (i.e., the minimum number of coins for smaller totals).

- **Parameters**:

  - `coins`: A list of integers representing the available coin denominations.
  - `total`: The target amount to reach.

- **Return Values**:

  - Returns `0` if `total` is less than or equal to `0`.
  - Returns `-1` if the `total` cannot be formed with the given coins.
  - Otherwise, it returns the fewest number of coins required to meet the `total`.

- The **time complexity** of the solution is a key evaluation criterion for this task.

---

## Files

- `0-making_change.py`: Contains the implementation of the `makeChange` function.
- `README.md`: The project documentation.

---
