#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

#include "heap.h"

// Define the heap_t type
typedef struct heap_s {
    int value;
    struct heap_s *left;
    struct heap_s *right;
    struct heap_s *parent;
} heap_t;

// Define the binary_tree_t type
typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
    struct binary_tree_s *parent;
} binary_tree_t;

// Include the necessary function declarations
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

int heap_extract(heap_t **root) {
  if (*root == NULL) {
    return 0;
  }

  int root_value = (*root)->value;

  // If the heap has only one node
  if ((*root)->left == NULL && (*root)->right == NULL) {
    free(*root);
    *root = NULL;
    return root_value;
  }

  // Find the last level-order node
  heap_t *last_node = *root;
  while (last_node->left != NULL || last_node->right != NULL) {
    if (last_node->right != NULL) {
      last_node = last_node->right;
    } else {
      last_node = last_node->left;
    }
  }

  // Replace the root with the last node
  (*root)->value = last_node->value;

  // Remove the last node
  if (last_node == last_node->parent->left) {
    last_node->parent->left = NULL;
  } else {
    last_node->parent->right = NULL;
  }
  free(last_node);

  // Heapify the tree
  heapify(root, 0);

  return root_value;
}


