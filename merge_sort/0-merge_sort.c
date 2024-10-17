#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_sort_rec - Recursively divides and sorts the array using merge sort.
 */
void merge_sort_rec(int *array, int *temp, int left, int right);

/**
 * merge - Merges two arrays of array[].
 * First sub-array is arr[left..mid]
 * Second sub-array is arr[mid+1..right]
 */
void merge(int *array, int left, int mid, int right, int *temp);

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

/**
 * merge_sort_rec - Recursively divides and sorts the array using merge sort.
 */
void merge_sort_rec(int *array, int *temp, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sort the left part
    merge_sort_rec(array, temp, left, mid);

    // Sort the right part
    merge_sort_rec(array, temp, mid + 1, right);

    // Merge the sorted parts
    merge(array, left, mid, right, temp);
}

/**
 * merge - Merges two arrays of array[].
 * First sub-array is arr[left..mid]
 * Second sub-array is arr[mid+1..right]
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1, k = left;

    printf("Merging...\n");
    print_array(array + left, mid - left + 1);
    print_array(array + mid + 1, right - mid);

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

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}
