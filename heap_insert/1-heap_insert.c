#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int btree_height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = btree_height(tree->left);

	if (tree->right != NULL)
		right_height = btree_height(tree->right);

	if (left_height > right_height)
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
	_Bool l_ch;
	_Bool r_ch;
	int l_per;
	int r_per;
	if (tree && btree_height(tree->left) == btree_height(tree->right))
	{
		if (btree_height(tree->left) == -1)
			return (1);
		l_ch = !((tree->left)->left) && !((tree->left)->right);
		r_ch = !((tree->right)->left) && !((tree->right)->right);
		if ((tree->left && l_ch) && (tree->right && r_ch))
			return (1);
		if (tree && tree->left && tree->right)
		{
			l_per = binary_tree_is_perfect(tree->left);
			r_per = binary_tree_is_perfect(tree->right);
			return (l_per && r_per);
		}
	}
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
	if (!node || !node->parent)
	{
		return;
	}
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
	if (!root || !*root)
	{
		*root = binary_tree_node(NULL, value);
		return *root;
	}

	heap_t *new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	heap_t *parent = find_parent(*root);
	if (!parent)
	{
		free(new_node);
		return NULL;
	}

	new_node->parent = parent;

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify(new_node);

	return (new_node);
}
