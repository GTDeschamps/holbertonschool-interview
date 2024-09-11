#include <stdio.h>
#include "search_algos.h"

/**
 * print_subarray - Prints the current subarray being searched.
 * @array: A pointer to the array.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */
void print_subarray(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	for (size_t i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
		{
			printf(", ");
		}
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence
 *                    of a value in a sorted array.
 * @array: A pointer to the array.
 * @start: The starting index of the current search range.
 * @end: The ending index of the current search range.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of value,
 *         or -1 if value is not found.
 */
int recursive_search(int *array, size_t start, size_t end, int value)
{
	if (start > end)
	{
		return (-1); /* Value not found */
	}

	print_subarray(array, start, end);

	size_t mid = start + (end - start) / 2;

	if (array[mid] == value)
	{
		/* Search in the left half to find the first occurrence */
		if (mid == start || array[mid - 1] != value)
		{
			return (mid); /* Found the first occurrence */
		}
		else
		{
			return (recursive_search(array, start, mid, value));
			/* Search in the left half */
		}
	}
	else if (array[mid] < value)
	{
		return (recursive_search(array, mid + 1, end, value));
		/* Search in the right half */
	}
	else
	{
		return (recursive_search(array, start, mid, value));
		/* Search in the left half */
	}
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   using binary search.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of value in array,
 *         or -1 if value is not present or if array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1); /* Invalid input */
	}

	return (recursive_search(array, 0, size - 1, value));
}
