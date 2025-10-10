#!/usr/bin/python3
"""Module for prime game function."""


def isWinner(x, nums):
    """Determines the winner of the prime game.

    Args:
            x (int): Number of rounds.
            nums (list): List of integers representing the
            upper limit for each round.

    Returns:
            str: "Maria" if Maria wins more rounds, "Ben"
            if Ben wins more rounds, or None if it's a tie.
    """
    if x < 1 or not nums or x != len(nums):
        return None

    def sieve_of_eratosthenes(n):
        """Returns a list indicating the primality of numbers up to n."""
        is_prime = [True] * (n + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False
        return is_prime

    max_num = max(nums)
    is_prime = sieve_of_eratosthenes(max_num)
    prime_count = [0] * (max_num + 1)

    for i in range(1, max_num + 1):
        prime_count[i] = prime_count[i - 1] + (1 if is_prime[i] else 0)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
