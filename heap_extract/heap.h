#ifndef HEAP_H
#define HEAP_H

typedef struct heap_node {
  int value;
  struct heap_node *parent;
  struct heap_node *left;
  struct heap_node *right;
} heap_t;

// Function prototypes
heap_t *heap_create(int value);
void heap_insert(heap_t **root, int value);
int heap_extract(heap_t **root);
void heapify(heap_t **root, int index);

#endif
