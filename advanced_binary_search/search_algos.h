#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h> // For size_t

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
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
