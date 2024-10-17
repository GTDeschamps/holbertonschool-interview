#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @size: The size of the array.
 */
void print_array( int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int left, int mid, int right, int *temp);

#endif /* SORT_H */
