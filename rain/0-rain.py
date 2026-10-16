#!/usr/bin/python3
"""
Module 0-rain: computes the amount of rainwater retained between walls.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls (list): list of non-negative integers representing
                      the heights of walls of unit width 1.

    Returns:
        int: total amount of rainwater retained (0 if the list is empty).
    """
    if not walls:
        return 0

    left_max = [0] * len(walls)
    right_max = [0] * len(walls)

    left_max[0] = walls[0]
    for i in range(1, len(walls)):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[-1] = walls[-1]
    for i in range(len(walls) - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    water_retained = 0
    for i in range(len(walls)):
        water_retained += min(left_max[i], right_max[i]) - walls[i]

    return water_retained
