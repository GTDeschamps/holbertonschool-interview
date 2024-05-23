#include <stdlib.h>
#include<stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Entry point
 *
 * @parent: Pointer to the parent
 * @value: value of the node
 *
 * Return: Always 0 (Success)
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
