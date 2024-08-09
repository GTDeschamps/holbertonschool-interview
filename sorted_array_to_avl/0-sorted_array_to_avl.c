#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

binary_tree_t *sorted_array_to_avl_helper(int *array, int start, int end,binary_tree_t *parent)
{
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;

    binary_tree_t *root = binary_tree_node(parent, array[mid]);

    root->left = sorted_array_to_avl_helper(array, start, mid - 1, root);
    root->right = sorted_array_to_avl_helper(array, mid + 1, end, root);

    return root;
}

// Function to build an AVL tree from a sorted array
binary_tree_t *sorted_array_to_avl(int *array, size_t size)
{
    binary_tree_t *tree = malloc(sizeof(binary_tree_t));
    if (!tree) {
        return NULL;
    }
    tree = sorted_array_to_avl_helper(array, 0, size - 1, NULL);
    return tree;
}

