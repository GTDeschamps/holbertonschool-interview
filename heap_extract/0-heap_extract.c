#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_size - Computes the size of the binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * swap_values - Swaps the values of two heap nodes
 * @a: first heap node
 * @b: second heap node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * get_last_node - Gets the last level-order node of the heap
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root, int size)
{
    heap_t *queue[size];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        heap_t *node = queue[front++];

        if (node->left)
            queue[rear++] = node->left;
        if (node->right)
            queue[rear++] = node->right;
    }

    return queue[front - 1];
}

/**
 * heapify_down - Ensures the heap property is maintained
 * @node: pointer to the current node being heapified
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;

    if (node->left && node->left->n > largest->n)
        largest = node->left;

    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        swap_values(node, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 if it fails
 */
int heap_extract(heap_t **root)
{
    if (!root || !(*root))
        return 0;

    int value = (*root)->n;
    heap_t *last_node = get_last_node(*root, binary_tree_size(*root));

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    swap_values(*root, last_node);

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);

    heapify_down(*root);

    return value;
}

