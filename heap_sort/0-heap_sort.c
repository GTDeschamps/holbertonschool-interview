#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void sift_down(int *array, size_t size, size_t root) {
    size_t largest = root; // Initialize largest as root
    size_t left_child = 2 * root + 1; // left child index
    size_t right_child = 2 * root + 2; // right child index

    // Check if left child exists and is greater than root
    if (left_child < size && array[left_child] > array[largest]) {
        largest = left_child;
    }

    // Check if right child exists and is greater than the largest so far
    if (right_child < size && array[right_child] > array[largest]) {
        largest = right_child;
    }

    // If largest is not root, swap with root and continue sifting down
    if (largest != root) {
        // Swap
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        // Print the array after swap
        for (size_t i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // Recursively sift down the affected subtree
        sift_down(array, size, largest);
    }
}

void heap_sort(int *array, size_t size) {
    // Build the heap (rearrange the array)
    for (size_t i = size / 2 - 1; i != (size_t)-1; i--) {
        sift_down(array, size, i);
    }

    // One by one extract elements from the heap
    for (size_t i = size - 1; i > 0; i--) {
        // Move current root to end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Print the array after swap
        for (size_t j = 0; j < size; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");

        // Call sift down on the reduced heap
        sift_down(array, i, 0);
    }
}
