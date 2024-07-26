#include <stdio.h>
#include <math.h>

/**
 * menger - Draw a 2D Menger Sponge of a given level
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size = pow(3, level);
    int i, j, x, y;

    if (level < 0)
    {
        return;
    }


    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            x = i;
            y = j;
            while (x > 0 || y > 0)
            {
                if (x % 3 == 1 && y % 3 == 1)
                {
                    break;
                }
                x /= 3;
                y /= 3;
            }
            if (x == 0 || y == 0)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
