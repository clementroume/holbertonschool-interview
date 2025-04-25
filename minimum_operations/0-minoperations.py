#!/usr/bin/python3
"""
Minimum Operations
Given a number n, write a method that calculates the fewest number of
operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n H
    characters in the file using a factorization strategy.

    Each operation is either:
    - "Copy All": copy the current content
    - "Paste": paste the last copied content
    """
    if n < 2:
        # No operation needed if n is 1 or less (can't copy from 1 H or no H)
        return 0

    operations = 0      # Total number of operations performed
    divisor = 2         # Start checking from the smallest prime number

    # Loop until we reduce n to 1
    while n > 1:
        # While the current divisor divides n
        while n % divisor == 0:
            # Add the divisor to the operation count:
            # - 1 "Copy All"
            # - (divisor - 1) "Paste"
            operations += divisor
            # Reduce n by dividing it by this factor
            n //= divisor
        # Try the next possible divisor
        divisor += 1

    return operations
