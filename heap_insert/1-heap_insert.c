#include <stdlib.h>
#include "binary_trees.h"

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
        return NULL;

    if (!*root)
        return *root = new_node;

    parent = find_parent(*root);

    new_node->parent = parent;

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    heapify(new_node);

    return new_node;
}

/**
 * find_parent - Finds the parent to insert the new node
 * @node: Pointer to the root node of the tree
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *node)
{
    if (!node)
        return NULL;

    if (!node->left || !node->right)
        return node;

    if (binary_tree_is_perfect(node->left) &&
        !binary_tree_is_perfect(node->right))
        return find_parent(node->right);
    else
        return find_parent(node->left);
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
