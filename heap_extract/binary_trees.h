#ifndef BINARY_TREES_H
#define BINARY_TREES_H

typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct heap_s
{
    int n;
    struct heap_s *parent;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

#endif /* BINARY_TREES_H */
