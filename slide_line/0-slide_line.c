#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * @brief Slides and merges an array of integers to the left or right.
 *
 * @param line The array of integers to be slided and merged.
 * @param size The number of elements in the array.
 * @param direction The direction of the slide and merge operation. Can be SLIDE_LEFT or SLIDE_RIGHT.
 *
 * @return 1 upon success, 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	int i, j, temp;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		/* Failure: invalid direction */
		return 0;
	}

	if (direction == SLIDE_LEFT)
	{
		/* Remove zeros from the left */
		i = 0;
		j = 0;
		while (j < (int)size)
		{
			if (line[j] != 0)
			{
				temp = line[i];
				line[i] = line[j];
				line[j] = temp;
				i++;
			}
			j++;
		}

		/* Merge identical numbers */
		i = 0;
		while (i < (int)size - 1)
		{
			if (line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
			i++;
		}

		/* Remove zeros from the left again */
		i = 0;
		j = 0;
		while (j < (int)size)
		{
			if (line[j] != 0)
			{
				temp = line[i];
				line[i] = line[j];
				line[j] = temp;
				i++;
			}
			j++;
		}
	}
	else
	{
		/* Remove zeros from the right */
		i = (int)size - 1;
		j = (int)size - 1;
		while (j >= 0)
		{
			if (line[j] != 0)
			{
				temp = line[i];
				line[i] = line[j];
				line[j] = temp;
				i--;
			}
			j--;
		}

		/* Merge identical numbers */
		i = (int)size - 1;
		while (i > 0)
		{
			if (line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
			i--;
		}

		/* Remove zeros from the right again */
		i = (int)size - 1;
		j = (int)size - 1;
		while (j >= 0)
		{
			if (line[j] != 0)
			{
				temp = line[i];
				line[i] = line[j];
				line[j] = temp;
				i--;
			}
			j--;
		}
	}

	/* Success */
	return 1;
}
