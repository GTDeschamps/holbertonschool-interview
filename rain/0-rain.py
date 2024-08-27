def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls (list[int]): A list of non-negative integers representing the heights of walls.

    Returns:
        int: Total amount of rainwater retained. Returns 0 if the list is empty.
    """
    # Check if the list is empty
    if not walls:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    # Calculate the maximum height to the left of each wall
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Calculate the maximum height to the right of each wall
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate the total water retained
    water_retained = 0
    for i in range(n):
        water_retained += min(left_max[i], right_max[i]) - walls[i]

    return water_retained
