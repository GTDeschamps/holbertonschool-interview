#include<stdio.h>
#include<stdlib.h>
#include <search.h>

typedef struct skiplist_node
{
    int n;
    size_t index;
    struct skiplist_node *next;
    struct skiplist_node *express;
} skiplist_t;

/**
 * search - search one by one
 *
 * @list: list of nodes
 * @index2: value for the print
 * @value: value to search
 *
 * Return: null or node with the value
 */
skiplist_t *search(skiplist_t *list, int index2, int value)
{
    skiplist_t *current = list;

    printf("Value found between indexes [%zu] and [%d]\n",
           current->index, index2);
    while (current != NULL)
    {
        printf("Value checked at index [%zu] = [%d]\n",
               current->index, current->n);
        if (current->n < value)
            current = current->next;
        else if (current->n == value)
            return (current);
        else
            return (NULL);
    }
    return (NULL);
}

/**
 * @brief Searches for a value in the skip list using linear search
 * @param list Pointer to the head of the skip list
 * @param value Value to search for
 * @return Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *current2;

	if (list == NULL)
		return (NULL);
	while (current->express != NULL)
	{
		printf("Value checked at index [%zu] = [%d]\n",
				current->express->index, current->express->n);
		if (current->express->n < value)
			current = current->express;
		else
			return (search(current, current->express->index, value));
	}
	current2 = current;
	while (current2->next != NULL)
		current2 = current2->next;
	return (search(current, current2->index, value));
}
