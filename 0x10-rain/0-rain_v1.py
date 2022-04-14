#!/usr/bin/python3
"""
    Rain
"""


def rain(walls):
    """
    Method to calculate how many square units of water will be retained after
    it rains.

    Parameters:
        walls: (list) non-negative integers.

    Returns:
        Integer indicating total amount of rainwater retained.
    """
    print(len(walls))

    if len(walls) == 0:
        return 0

    walls_dict = {}
    # { "width": idx...}

    for idx, width in enumerate(walls):
        print(idx, width)
        if width != 0:
            walls_dict[str(width)] = idx

        print(walls_dict)
    keys_list = list(walls_dict)
    print(keys_list)
    square_units_of_water = 0
    for current_wall_key in keys_list[:-1]:
        print("test")
        next_wall_key = keys_list[keys_list.index(current_wall_key) + 1]

        # mul is the size the retained space by rainwater
        mul = walls_dict[next_wall_key] - walls_dict[current_wall_key] - 1
        print(int(current_wall_key))
        if int(current_wall_key) <= int(next_wall_key):
            print("test0")
            square_units_of_water += int(current_wall_key) * mul
        else:
            print("test0")

            square_units_of_water += int(next_wall_key) * mul

    return square_units_of_water
