#!/usr/bin/python3
def minOperations(n):
    """Calculate the fewest number of operations to get n H characters."""
    if n < 2:
        return 0
    ops = 0
    factor = 2
    while n > 1:
        while n % factor == 0:
            ops += factor
            n //= factor
        factor += 1
    return ops
