#!/usr/bin/python3
"""
    Making Change
"""

def _get_change_making_matrix(set_of_coins, r: int):
    """
        Get change making matrix
    """
    m = [[0 for _ in range(r + 1)] for _ in range(len(set_of_coins) + 1)]
    print(m)
    for i in range(1, r + 1):
        m[0][i] = float('inf')  # By default there is no way of making change
    return m

def makeChange(coins, total):
    """
    Method:
    -------
        Determine the fewest number of coins needed to meet a given amount.

    Parameters:
    -----------
        total(integer): a given amount.
        coins(list): values of the coins in your possession.

    Returns:
    --------
        Fewest number of coins needed to meet total.
    """
    m = _get_change_making_matrix(coins, total)
    for c, coin in enumerate(coins, 1):
        print(c, coin)
        for r in range(1, total + 1):
            print(r)
            # Just use the coin
            if coin == r:
                m[c][r] = 1
            # coin cannot be included.
            # Use the previous solution for making r,
            # excluding coin
            elif coin > r:
                m[c][r] = m[c - 1][r]
            # coin can be used.
            # Decide which one of the following solutions is the best:
            # 1. Using the previous solution for making r (without using coin).
            # 2. Using the previous solution for making r - coin (without
            #      using coin) plus this 1 extra coin.
            else:
                m[c][r] = min(m[c - 1][r], 1 + m[c][r - coin])
        print(m)
    return m[-1][-1]
