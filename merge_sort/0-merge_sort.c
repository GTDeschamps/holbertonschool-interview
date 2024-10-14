#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;

	int *L = malloc(sizeof(int) * n1);
	int *R = malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, 0, mid - 1, size - 1);
}
