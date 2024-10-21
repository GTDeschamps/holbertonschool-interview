#!/usr/bin/python3
"""
function to determine the fewest number of coins needed
to meet a given amount total.
"""


def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize the dp array where dp[i] is the minimum number of coins
    # need to make i.
    dp = [float('inf')]*(total + 1)
    dp[0] = 0 # 0 coins are needed to make 0

    # iterate over all amounts from 1 to total
    for i in range(1, total + 1):
        # check each coin to find the fewest coins for the current amount
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin]+1)

    # if dp[total] is still infinity, it means we cannot make the total
    # with the given coins.
    return dp[total] if dp[total] != float('inf') else -1
