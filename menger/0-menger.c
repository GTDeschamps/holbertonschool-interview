#include <stdio.h>
#include <math.h>

/**
 * menger - Draw a 2D Menger Sponge of a given level
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
    if (level < 0)
    {
        return;
    }

    int size = pow(3, level);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int x = i;
            int y = j;
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
