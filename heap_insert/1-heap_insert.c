#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * bubble_up - Ensures the max heap property by bubbling up
 * @node: Node to start bubbling up from
 */
void bubble_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * find_insertion_point -
 * Finds the insertion point for a new node in level order
 * @root: Pointer to the root of the heap
 * Return: Pointer to the insertion point node
 */
heap_t *find_insertion_point(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;
	while (front < rear)
	{
		heap_t *node = queue[front++];

		if (!node->left || !node->right)
			return (node);
		queue[rear++] = node->left;
		queue[rear++] = node->right;
	}
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert_point;
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	insert_point = find_insertion_point(*root);

	new_node = binary_tree_node(insert_point, value);

	if (!new_node)
		return (NULL);

	if (!insert_point->left)
		insert_point->left = new_node;
	else
		insert_point->right = new_node;

	bubble_up(new_node);
	return (new_node);
}
