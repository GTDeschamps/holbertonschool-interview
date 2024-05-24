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
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left);

	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right);

	if(left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}


/**
 * binary_tree_is_perfect - checks if tree is perfect
 *@tree: tree to check
 *
 *Return: 1 perfect 0 not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, i, j, sum = 0, pow;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	for (i = 0; i <= binary_tree_height(tree); i++)
	{
		for (j = 0, pow = 1; j < i; j++)
			pow *= 2;
		sum += pow;
	}
	if (sum == size)
		return (1);
	return (0);
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
