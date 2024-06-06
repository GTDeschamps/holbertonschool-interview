#include "sandpiles.h"
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, k, l, sum, toppling;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = grid1[i][j] + grid2[i][j];
			toppling = sum / 4;
			grid1[i][j] = sum % 4;

			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					if (k == i && l == j)
					{
						continue;
					}
					grid1[k][l] += toppling;
				}
			}
		}
	}

	while (1)
	{
		toppling = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					toppling++;
					grid1[i][j] -= 4;
				}
			}
		}
		if (toppling == 0)
		{
			break;
		}
	}
}
