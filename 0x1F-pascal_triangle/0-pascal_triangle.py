#!/usr/bin/python3
"""Pascal's Triangle module"""


def pascal_triangle(n):
    """
    Method:
        Constructs the pascal's triangle.

    Parameters:
        n (int): is an integer

    Returns:
        list(List): Contains the different level of pascal's triangle.
    """
    if n <= 0:
        return []
    result = []
    for i in range(n):
        current = list()
        for j in range(i + 1):
            if j == 0 or j == i:
                current.append(1)
            else:
                current.append(result[i - 1][j - 1] + result[i - 1][j])
        result.append(current)
    return result
