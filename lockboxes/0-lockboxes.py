#!/usr/bin/python3
"""First Algorythm interview"""

def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened.

    Args:
    boxes (list): A list of lists where each inner list represents a box and its keys.

    Returns:
    bool: True if all boxes can be opened, False otherwise.
    """
    if not boxes:
        return False

    keys = [0]  # List to store keys available to open boxes
    unlocked = [False] * len(boxes)  # List to track if a box is unlocked

    while keys:
        box = keys.pop(0)
        unlocked[box] = True

        for key in boxes[box]:
            if key < len(boxes) and not unlocked[key]:
                keys.append(key)

    return all(unlocked)
