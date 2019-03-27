#ifndef EI1710_HEAP_H

#include "../vector/vector.h"

//vectorを使って二分ヒープ

typedef struct {
	Vector storage;
	int (*compare)(const void *, const void *);
} Heap;

//Heap構造体の初期化
void Heap_init(Heap *heap, size_t data_size, int (*compare)(const void *, const void*));

//Heapにデータを追加
int Heap_add(Heap *heap, void *);

//Heapからデータを取り出す
//取り出したデータは削除される
int Heap_top(Heap *heap, void *);

//Heapに格納されているデータ数を数える
size_t Heap_size(Heap *heap);

//Heapをクリア
void Heap_clear(Heap *heap);

#endif
