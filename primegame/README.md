# Prime Game

## Description

This project implements a Python solution to determine the winner of a game based on prime numbers. The game pits two players, Maria and Ben, against each other over several rounds.

The rules of the game are as follows: For each round, a number `n` is chosen. The players have a set of consecutive integers from 1 to `n`. In turns, a player picks a prime number from the set and removes that number and all of its multiples. The player who can no longer make a move (because there are no prime numbers left to choose) loses the round.

Maria always plays first. The function determines who wins the most rounds.

## Implementation Details

The program provides a function, `isWinner(x, nums)`, which analyzes a series of rounds to determine the final winner.

### Winning Logic

A win in any given round depends on the parity of the number of available prime numbers. If the count of prime numbers from 1 to `n` is odd, the first player (Maria) will always win. If it is even, the second player (Ben) will win.

The algorithm works as follows:

1. To optimize performance, it uses the **Sieve of Eratosthenes** to pre-calculate all prime numbers up to the maximum value of `n` across all rounds.
2. It then iterates through each round `n` from the `nums` list.
3. For each `n`, it counts the number of prime numbers less than or equal to it.
4. If this count is odd, Maria wins the round. If it's even, Ben wins.
5. The scores are tallied, and the player with the most wins is declared the winner.

## Files

### `0-prime_game.py`

Contains the main logic for solving the game.

- `isWinner(x, nums)`: The main function that takes `x` (the number of rounds) and `nums` (a list of `n` values for each round) as arguments. It returns the name of the player who won the most rounds (`"Maria"` or `"Ben"`), or `None` in case of a tie.

### `main_0.py`

Provides an example of how to use and test the `isWinner` function with a series of rounds and displays the result.
