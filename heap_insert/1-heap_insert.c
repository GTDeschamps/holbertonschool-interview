#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int btree_height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = btree_height(tree->left);

	if (tree->right != NULL)
		right_height = btree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_perfect - checks if tree is perfect
 *@tree: tree to check
 *
 *Return: 1 perfect 0 not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	_Bool l_ch;
	_Bool r_ch;
	int l_per;
	int r_per;
	if (tree && btree_height(tree->left) == btree_height(tree->right))
	{
		if (btree_height(tree->left) == -1)
			return (1);
		l_ch = !((tree->left)->left) && !((tree->left)->right);
		r_ch = !((tree->right)->left) && !((tree->right)->right);
		if ((tree->left && l_ch) && (tree->right && r_ch))
			return (1);
		if (tree && tree->left && tree->right)
		{
			l_per = binary_tree_is_perfect(tree->left);
			r_per = binary_tree_is_perfect(tree->right);
			return (l_per && r_per);
		}
	}
	return (0);
}

/**
 * swap_values - Swaps the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * bubble_up - Ensures the max heap property by bubbling up
 * @node: Node to start bubbling up from
 */
void bubble_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * find_insertion_point - Finds the insertion point for a new node in level order
 * @root: Pointer to the root of the heap
 * Return: Pointer to the insertion point node
 */
heap_t *find_insertion_point(heap_t *root)
{
    heap_t *queue[1024]; // Assuming the heap won't exceed 1024 nodes for simplicity
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear)
    {
        heap_t *node = queue[front++];
        if (!node->left || !node->right)
            return node;
        queue[rear++] = node->left;
        queue[rear++] = node->right;
    }
    return NULL;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (!root)
        return NULL;

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return *root;
    }

    heap_t *insert_point = find_insertion_point(*root);
    heap_t *new_node = binary_tree_node(insert_point, value);

    if (insert_point->left == NULL)
        insert_point->left = new_node;
    else
        insert_point->right = new_node;

    bubble_up(new_node);
    return new_node;
}
