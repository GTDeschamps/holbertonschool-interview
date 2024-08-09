#ifndef BINARY_TREES_H
#define BINARY_TREES_H

typedef struct binary_tree_s binary_tree_t;
typedef struct avl_tree_s avl_t;

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
    binary_tree_t *parent;
    binary_tree_t *left;
    binary_tree_t *right;
};

/**
 * struct avl_tree_s - AVL tree
 *
 * @root: Pointer to the root node of the AVL tree
 */
struct avl_tree_s
{
    binary_tree_t *root;
};

avl_t *sorted_array_to_avl(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);

#endif
