#include <stdio.h>
#include "sandpiles.h"

#define SIZE 3

void topple(int grid[3][3])
{
/*create grid*/
	int next[3][3] = {{0}};

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int grains = grid[i][j];
			if (grains >= 4)
			{
				grid[i][j] -= 4;
				if (i > 0)
					next[i - 1][j] += 1;
				if (i < SIZE - 1)
					next[i + 1][j] += 1;
				if (j > 0)
					next[i][j - 1] += 1;
				if (j < SIZE - 1)
					next[i][j + 1] += 1;
			}
			next[i][j] += grid[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid[i][j] = next[i][j];
		}
	}
}

void print_grid(int grid[3][3])
{
/*print the grid*/
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	/* Add the two sandpiles together*/
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/*Topple the sandpile until it becomes stable*/
	while (1)
	{
		int unstable = 0;
		for (int i = 0; i < SIZE; i++)
		{

			for (int j = 0; j < SIZE; j++)
			{
				if (grid1[i][j] >= 4)
				{
					unstable = 1;
					break;
				}
			}
			if (unstable)
				break;
		}

		if (unstable)
		{
			printf("Unstable Sandpile:\n");
			print_grid(grid1);
			printf("\n");
			topple(grid1);
		}
		else
		{
			break;
		}
	}
	print_grid(grid1);
}
