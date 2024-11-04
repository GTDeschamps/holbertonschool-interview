#ifndef SORT_H
#define SORT_H

/**
 * print_array - print the element of the array
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 *
 * Return: void
 */
void print_array(const int *array, size_t size);


/**
 * radix_sort - function that sorts an array of integers
 *              in ascending order using the Radix sort algorithm
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 *
 * Return: void
 */
void radix_sort(int *array, size_t size);

#endif /*SORT_H*/
