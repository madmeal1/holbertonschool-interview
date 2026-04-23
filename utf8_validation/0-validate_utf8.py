#!/usr/bin/python3
"""
Module for UTF-8 validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: list of integers (only 8 least significant bits matter)

    Return:
        True if data is a valid UTF-8 encoding, else False
    """
    continuation_bytes = 0

    for value in data:
        byte = value & 0xFF

        if continuation_bytes > 0:
            if byte >> 6 != 0b10:
                return False
            continuation_bytes -= 1
        else:
            if byte >> 7 == 0b0:
                continuation_bytes = 0
            elif byte >> 5 == 0b110:
                continuation_bytes = 1
            elif byte >> 4 == 0b1110:
                continuation_bytes = 2
            elif byte >> 3 == 0b11110:
                continuation_bytes = 3
            else:
                return False

    return continuation_bytes == 0
