#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a singly linked list.
 * @head: Pointer to the pointer of the head of the list.
 * Return: Pointer to the head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return (*head);
}


/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 * Return: 1 if it is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    listint_t *slow = *head, *fast = *head;
    listint_t *first_half_end = NULL, *second_half_start = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    first_half_end = slow;
    second_half_start = reverse_listint(&first_half_end);

    listint_t *first_half_iter = *head;
    listint_t *second_half_iter = second_half_start;
    int palindrome = 1;

    while (second_half_iter != NULL)
    {
        if (first_half_iter->n != second_half_iter->n)
        {
            palindrome = 0;
            break;
        }
        first_half_iter = first_half_iter->next;
        second_half_iter = second_half_iter->next;
    }

    reverse_listint(&second_half_start);

    return (palindrome);
}
