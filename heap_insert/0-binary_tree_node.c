#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
{
	* binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    if (new_node == NULL) {
        return NULL;  // Return NULL on failure
    }

    new_node->parent = parent;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
