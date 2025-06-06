#!/usr/bin/python3
"""
Module for calculating the amount of rain that can be trapped between walls.
"""


def rain(walls):
    """
    Calculates the amount of rain that can be trapped between walls.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total units of rain that can be trapped.
    """
    # If there are no walls, no rain can be trapped.
    if not walls:
        return 0

    n = len(walls)
    total_rain = 0

    # `left_max[i]` will store the height of the tallest wall
    # to the left of i (inclusive).
    left_max = [0] * n
    # `right_max[i]` will store the height of the tallest wall
    # to the right of i (inclusive).
    right_max = [0] * n

    # --- First pass: from left to right ---
    # Fill the left_max array.
    left_max[0] = walls[0]
    for i in range(1, n):
        # The tallest wall up to `i` is the maximum of the tallest wall
        # up to `i-1` and the current wall `walls[i]`.
        left_max[i] = max(left_max[i - 1], walls[i])

    # --- Second pass: from right to left ---
    # Fill the right_max array.
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        # The tallest wall from the right is the maximum of the tallest wall
        # from `i+1` and the current wall `walls[i]`.
        right_max[i] = max(right_max[i + 1], walls[i])

    # --- Final calculation of trapped water ---
    # For each wall, calculate the water it can hold above it.
    for i in range(n):
        # The water level at a position `i` is determined by the shorter of
        # the two highest surrounding walls (`left_max[i]` and `right_max[i]`).
        water_level = min(left_max[i], right_max[i])

        # The amount of water above the wall at `i` is the difference between
        # the water level and the height of the wall itself.
        trapped_water = water_level - walls[i]

        # Add this amount to the total (if it's positive).
        if trapped_water > 0:
            total_rain += trapped_water

    return total_rain
