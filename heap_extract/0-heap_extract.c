#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * swap_values - Swaps the values of two heap nodes
 * @a: first heap node
 * @b: second heap node
 */
void swap_values(heap_t *a, heap_t *b)
{
  int temp = a->n;
  a->n = b->n;
  b->n = temp;
}

/**
 * get_last_node - Gets the last level-order node of the heap
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 * Return: pointer to the last node
 */
heap_t *getLastNode(heap_t *root)
{
  heap_t *queue[100], *lastNode = NULL, *current;
  int front = 0, rear = 0;

  if (!root)
    return (NULL);

  queue[rear++] = root;

  while (front < rear)
  {
    current = queue[front++];
    lastNode = current;

    if (current->left)
      queue[rear++] = current->left;
    if (current->right)
      queue[rear++] = current->right;
  }

  return (lastNode);
}

/**
 * heapify_down - Ensures the heap property is maintained
 * @node: pointer to the current node being heapified
 */
void heapify_down(heap_t *node)
{
  heap_t *largest = node;

  if (!node)
    return;

  if (node->left && node->left->n > largest->n)
    largest = node->left;

  if (node->right && node->right->n > largest->n)
    largest = node->right;

  if (largest != node)
  {
    swap_values(node, largest);
    heapify_down(largest);
  }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 if it fails
 */
int heap_extract(heap_t **root)
{
  int maxValue;
  heap_t *lastNode;

  if (!(*root))
    return (0);

  lastNode = getLastNode(*root);
  if (!lastNode)
    return (0);

  maxValue = (*root)->n;

  if (*root == lastNode)
  {
    free(*root);
    *root = NULL;
    return (maxValue);
  }

  (*root)->n = lastNode->n;

  if (lastNode->parent->left == lastNode)
    lastNode->parent->left = NULL;
  else
    lastNode->parent->right = NULL;

  free(lastNode);

  heapify_down(*root);
  return (maxValue);
}
