#!/usr/bin/python3

def canUnlockAll(boxes):
    """Determines if all boxes can be opened.

    Args:
        boxes (list): A list of lists representing the boxes and their keys.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    unlocked = [0]
    keys = set(unlocked)

    for i in unlocked:
        for key in boxes[i]:
            if key not in keys and key < len(boxes):
                keys.add(key)
                unlocked.append(key)

    return len(keys) == len(boxes)
