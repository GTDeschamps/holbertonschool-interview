#!/usr/bin/python3
def island_perimeter(grid):
    """
    Given a 2D grid representing an island, returns the perimeter of the island.

    Args:
        grid: A list of lists of integers representing the island.
            0 represents water
            1 represents land
            Each cell is square, with a side length of 1
            Cells are connected horizontally/vertically (not diagonally).
            grid is rectangular, with its width and height not exceeding 100
            The grid is completely surrounded by water
            There is only one island (or nothing).
            The island doesn’t have “lakes”
            (water inside that isn’t connected
            to the water surrounding the island).

    Returns:
        The perimeter of the island.
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                # Check if the cell has a neighbor to the right
                if j + 1 < len(grid[0]) and grid[i][j + 1] == 0:
                    perimeter += 1
                # Check if the cell has a neighbor to the left
                if j - 1 >= 0 and grid[i][j - 1] == 0:
                    perimeter += 1
                # Check if the cell has a neighbor below
                if i + 1 < len(grid) and grid[i + 1][j] == 0:
                    perimeter += 1
                # Check if the cell has a neighbor above
                if i - 1 >= 0 and grid[i - 1][j] == 0:
                    perimeter += 1
    return perimeter
