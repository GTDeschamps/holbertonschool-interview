#ifndef BINARY_TREES_H
#define BINARY_TREES_H

typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;


void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H */
