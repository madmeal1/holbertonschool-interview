#!/usr/bin/python3
"""
describes a function that determines if all boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    """
    if not boxes or not isinstance(boxes, list):
        return False

    opened = set([0])
    keys = [0]

    while keys:
        current_box = keys.pop()
        for key in boxes[current_box]:
            if key not in opened and 0 <= key < len(boxes):
                opened.add(key)
                keys.append(key)

    return len(opened) == len(boxes)
