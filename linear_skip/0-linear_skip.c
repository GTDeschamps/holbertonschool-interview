/**
 * @file skiplist.c
 * @brief Implementation of a skip list data structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <math.h>

/**
 * @struct skiplist_s
 * @brief Node structure for the skip list
 */
typedef struct skiplist_s
{
    int n; /**< Value stored in the node */
    int index; /**< Index of the node in the list */
    struct skiplist_s *next; /**< Pointer to the next node in the list */
    struct skiplist_s *express; /**< Pointer to the express lane node */
} skiplist_t;

/**
 * @brief Searches for a value in the skip list using linear search
 * @param list Pointer to the head of the skip list
 * @param value Value to search for
 * @return Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (list == NULL)
        return NULL;

    int size = 0;
    skiplist_t *current = list;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    current = list;
    while (current != NULL)
    {
        printf("Value checked at index [%d] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return current;
        if (current->express != NULL && current->express->n <= value)
            current = current->express;
        else
            current = current->next;
    }

    return NULL;
}
