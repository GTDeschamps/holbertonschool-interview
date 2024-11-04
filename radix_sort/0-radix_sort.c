#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/* Helper function to find the maximum value in the array */
int get_max(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/* Counting sort for each digit */
void counting_sort(int *array, size_t size, int exp) {
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};

    /* Count occurrences of each digit */
    for (size_t i = 0; i < size; i++) {
        int index = (array[i] / exp) % 10;
        count[index]++;
    }

    /* Update count[i] to hold actual positions in output */
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    /* Build output array */
    for (int i = size - 1; i >= 0; i--) {
        int index = (array[i] / exp) % 10;
        output[count[index] - 1] = array[i];
        count[index]--;
    }

    /* Copy output array to the original array */
    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

/* Radix Sort implementation */
void radix_sort(int *array, size_t size) {
    if (size < 2) {
        return;
    }

    /* Find the maximum number to determine the number of digits */
    int max = get_max(array, size);

    /* Apply counting sort for each digit */
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(array, size, exp);
        print_array(array, size);  // Print array after sorting each digit place
    }
}
