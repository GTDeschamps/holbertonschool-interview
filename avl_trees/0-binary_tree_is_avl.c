#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height of
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (tree->left != NULL && tree->left->n >= tree->n)
        return (0);

    if (tree->right != NULL && tree->right->n <= tree->n)
        return (0);

    if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
        return (0);

    return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height;
    int right_height;

    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1); // It's an AVL tree

    if (!binary_tree_is_bst(tree))
        return (0);

    left_height = (int)binary_tree_height(tree->left);
    right_height = (int)binary_tree_height(tree->right);

    if (abs(left_height - right_height) > 1)
        return (0);

    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}
