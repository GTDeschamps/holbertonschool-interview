#ifndef SORT_H
#define SORT_H

#include <stddef.h>

// Function prototypes

void sift_down(int *array, size_t size, size_t root, size_t full_size);
void heap_sort(int *array, size_t size);
void print_array(int *array, size_t size);

#endif // SORT_H
