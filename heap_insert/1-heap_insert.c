#include <stdlib.h>
#include "binary_trees.h"

/**
 *  * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

 /**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = binary_tree_node(NULL, value);
	heap_t *parent = NULL;

	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	parent = find_parent(*root);

	new_node->parent = parent;

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify(new_node);

	return (new_node);
}

/**
 * find_parent - Finds the parent to insert the new node
 * @node: Pointer to the root node of the tree
 * Return: Pointer to the parent node
 */

heap_t *find_parent(heap_t *node)
{
	if (!node)
		return (NULL);

	if (!node->left || !node->right)
		return (node);

	if (binary_tree_is_perfect(node->left) &&
		!binary_tree_is_perfect(node->right))
		return (find_parent(node->right));
	else
		return (find_parent(node->left));
}

/**
 * heapify - Maintains the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */

void heapify(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}
