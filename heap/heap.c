#include "heap.h"

#define parent_index(X) (((X) - 1) / 2)
#define left_index(X) ((X) * 2 + 1)
#define right_index(X) ((X) * 2 + 2)

void Heap_trickleDown(int i); 
void Heap_bubble_up(int i);
//size Byteのメモリオブジェクトを入れ替え
void memswap(void *x, void *y, size_t size);

void Heap_init(Heap *heap, size_t data_size, int (*compare)(const void *, const void *))
{
	Vector_init(&(heap->storage), data_size, 0);
	heap->compare = compare;

	return;
}

int Heap_add(heap *heap, void *data)
{
	if (Vector_push_back(&(heap->storage), data) == 0) {
		return 0;
	}

	Heap_bubble_up(Vector_size(&(heap->storage)) - 1);

	return 1;
}

void Heap_top(Heap *heap, void *data)
{
	memcpy(data, Vector_array(&(heap->storage), 0), 
		heap->storage->data_size);

	return;
}

void Heap_remove(Heap *heap)
{

}

//----
void Heap_bubble_up(int i) {
	int p = parent(i);
	
	while(i > 0 && heap->compare(Vector_array(&(heap->storage), i),
				Vector_array(&(heap->storage), p)) < 0) {

		memswap(Vector_array(&(heap->storage), i),
				Vector_array(&(heap->storage), p),
				heap->storage->data_size);
		i = p;
		p = parent(i);
	}

	return;
}

//Xor Swap
void memswap(void *x, void *y, size_t size)
{
	if (x == y) {
		return;
	} else {
		while (size--) {
			*((unsigned char *)x + size) ^= *((unsigned char *)y + size);
			*((unsigned char *)y + size) ^= *((unsigned char *)x + size);
			*((unsigned char *)x + size) ^= *((unsigned char *)y + size);
		}

		return;
	}
}
