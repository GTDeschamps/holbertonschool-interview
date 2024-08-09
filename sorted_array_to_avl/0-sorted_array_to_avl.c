#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

avl_t *array_to_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = array_to_avl(array, start, mid - 1, root);
	root->right = array_to_avl(array, mid + 1, end, root);

	return (root);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (array_to_avl(array, 0, size - 1, NULL));
}
