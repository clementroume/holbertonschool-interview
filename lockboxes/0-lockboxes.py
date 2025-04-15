#!/usr/bin/python3
"""Module to determine if all boxes can be opened."""


def canUnlockAll(boxes):
    """Determines if all boxes can be opened.

    Args:
        boxes (list): A list of lists representing the boxes and their keys.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    unlocked = [0]  # Start with the first box (index 0) unlocked
    keys = set(unlocked)  # Initialize a set of keys with the unlocked box

    # Loop through each unlocked box (starting with box 0)
    for i in unlocked:
        # For each key in the current unlocked box, attempt to open other boxes
        for key in boxes[i]:
            # If the key isn't already in the set of keys and is a valid index,
            # unlock the box
            if key not in keys and key < len(boxes):
                keys.add(key)  # Add the new key to the set of keys
                unlocked.append(key)  # Mark the box as unlocked

    # If the number of unlocked boxes is equal to the total number of boxes,
    # return True
    return len(keys) == len(boxes)
