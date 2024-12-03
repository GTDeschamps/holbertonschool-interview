#!/usr/bin/python3

def pascal_triangle(n):
    """
    This function returns a list of lists of integers
    representing Pascal's triangle of n.

    Args:
    n: An integer representing the number of rows in the Pascal's triangle.

    Returns:
        A list of lists of integers representing Pascal's triangle.
    """

    # Check if the input is less than or equal to 0
    if n <= 0:
        return []  # Return an empty list for non-positive input

    # Initialize the triangle with the first row
    triangle = [[1]]

    # Generate each row of Pascal's triangle
    for i in range(1, n):
        row = [1] # Start each row with a 1
        for j in range(1, i):
            # Each triangle element is the sum of the two elements above it
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        row.append(1) # End each row with a 1
        triangle.append(row) # Add the completed row to the triangle

    return triangle # Return the completed Pascal's triangle
