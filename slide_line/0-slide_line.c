#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT) {
        return 0;
    }

    size_t i, j;
    int temp;

    if (direction == SLIDE_LEFT) {
        // Remove zeros from the left
        i = 0;
        j = 0;
        while (j < size) {
            if (line[j] != 0) {
                temp = line[i];
                line[i] = line[j];
                line[j] = temp;
                i++;
            }
            j++;
        }

        // Merge identical numbers
        i = 0;
        while (i < size - 1) {
            if (line[i] == line[i + 1]) {
                line[i] *= 2;
                line[i + 1] = 0;
            }
            i++;
        }

        // Remove zeros from the left again
        i = 0;
        j = 0;
        while (j < size) {
            if (line[j] != 0) {
                temp = line[i];
                line[i] = line[j];
                line[j] = temp;
                i++;
            }
            j++;
        }
    } else {
        // Remove zeros from the right
        i = size - 1;
        j = size - 1;
        while (j > 0) {
            if (line[j] != 0) {
                temp = line[i];
                line[i] = line[j];
                line[j] = temp;
                i--;
            }
            j--;
        }

        // Merge identical numbers
        i = size - 1;
        while (i > 0) {
            if (line[i] == line[i - 1]) {
                line[i] *= 2;
                line[i - 1] = 0;
            }
            i--;
        }

        // Remove zeros from the right again
        i = size - 1;
        j = size - 1;
        while (j > 0) {
            if (line[j] != 0) {
                temp = line[i];
                line[i] = line[j];
                line[j] = temp;
                i--;
            }
            j--;
        }
    }

    return 1;
}
