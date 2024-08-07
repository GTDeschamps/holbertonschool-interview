#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

// Define the structure for an AVL tree node
typedef struct avl_node {
    int value;
    struct avl_node *left;
    struct avl_node *right;
    int height;
} avl_node_t;

// Define the structure for an AVL tree
typedef struct avl_tree {
    avl_node_t *root;
} avl_t;

// Function to create a new AVL tree node
avl_node_t *create_node(int value) {
    avl_node_t *node = malloc(sizeof(avl_node_t));
    if (!node) {
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to build an AVL tree from a sorted array
avl_t *sorted_array_to_avl(int *array, size_t size) {
    // Base case: if the array is empty, return NULL
    if (size == 0) {
        return NULL;
    }

    // Find the middle element of the array
    size_t mid = size / 2;

    // Create a new AVL tree node with the middle element
    avl_node_t *root = create_node(array[mid]);

    // Recursively build the left and right subtrees
    root->left = sorted_array_to_avl(array, mid);
    root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

    // Update the height of the root node
    root->height = 1 + (root->left ? root->left->height : 0) + (root->right ? root->right->height : 0);

    // Create a new AVL tree with the root node
    avl_t *tree = malloc(sizeof(avl_t));
    if (!tree) {
        return NULL;
    }
    tree->root = root;

    return tree;
}
