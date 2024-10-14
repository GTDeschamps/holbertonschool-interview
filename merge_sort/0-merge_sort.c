#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * merge - Merges two sub-arrays of array[].
 * First sub-array is arr[left..mid]
 * Second sub-array is arr[mid+1..right]
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temp[i];
}

/**
 * merge_sort_rec - Recursively divides and sorts the array using merge sort.
 */
void merge_sort_rec(int *array, int *temp, size_t left, size_t right)
{
    if (left >= right)
        return;

    size_t mid = left + (right - left) / 2;

    // Sort the left part
    merge_sort_rec(array, temp, left, mid);

    // Sort the right part
    merge_sort_rec(array, temp, mid + 1, right);

    // Merge the sorted parts
    merge(array, temp, left, mid, right);

    // Print the array after merging for visualization
    printf("Merged array: ");
    for (size_t i = left; i <= right; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**
 * merge_sort - The top-level function that starts merge sort.
 */
void merge_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    int *temp = (int *)malloc(size * sizeof(int));
    if (!temp)
        return;

    merge_sort_rec(array, temp, 0, size - 1);

    free(temp);
}
