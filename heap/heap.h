#ifndef EI1710_HEAP_H

#include "../vector/vector.h"

//vectorを使って二分ヒープ

typedef struct {
	Vector storage;
	int (*compare)(const void *, const void *);
} Heap;

void Heap_init(Heap *heap, size_t data_size, int (*compare)(const void *, const void*));
int Heap_add(Heap *heap, void *);
void Heap_top(Heap *heap, void *);
void Heap_remove(Heap *heap);
void Heap_clear(Heap *heap);

#endif
