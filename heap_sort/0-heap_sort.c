#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void sift_down(int *array, size_t size, size_t root, size_t full_size)
{
    size_t largest = root;
    size_t left_child = 2 * root + 1;
    size_t right_child = 2 * root + 2;

    // Check if left child exists and is greater than root
    if (left_child < size && array[left_child] > array[largest])
    {
        largest = left_child;
    }

    // Check if right child exists and is greater than the largest so far
    if (right_child < size && array[right_child] > array[largest])
    {
        largest = right_child;
    }

    // If largest is not root, swap with root and continue sifting down
    if (largest != root)
    {
        // Swap
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        print_array(array, full_size);

        // Recursively sift down the affected subtree
        sift_down(array, size, largest, full_size);
    }
}

void heap_sort(int *array, size_t size)
{
    // Build the heap (rearrange the array)
    for (size_t i = size / 2; i > 0; i--)
    {
        sift_down(array, size, i - 1, size);
    }

    // One by one extract elements from the heap
    for (size_t i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);
        sift_down(array, i, 0, size);
    }
}
