#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: The first grid
 * @grid2: The second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, sum, toppling;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = grid1[i][j] + grid2[i][j];
			grid1[i][j] = sum;
		}
	}

	while (1)
	{
		toppling = 0;
		int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					toppling++;
					temp[i][j] = grid1[i][j] - 4;
					if (i > 0)
						temp[i - 1][j]++;
					if (i < 2)
						temp[i + 1][j]++;
					if (j > 0)
						temp[i][j - 1]++;
					if (j < 2)
						temp[i][j + 1]++;
				}
				else
				{
					temp[i][j] = grid1[i][j];
				}
			}
		}

		if (toppling == 0)
		{
			break;
		}

		printf("=\n");
		print_grid(temp);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = temp[i][j];
			}
		}
	}
}
