#!/usr/bin/python3
"""Making Change Module"""


def makeChange(coins, total):
    """Determines the fewest number of coins needed to meet a given amount.

    Args:
            coins (list): List of coin denominations.
            total (int): The total amount of money to make change for.

    Returns:
            int: The fewest number of coins needed, or -1 if it's not possible.
    """
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for x in range(coin, total + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
