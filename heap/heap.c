#include "heap.h"

#define parent_index(X) (((X) - 1) / 2)
#define left_index(X) ((X) * 2 + 1)
#define right_index(X) ((X) * 2 + 2)

//Heapの根を削除
void Heap_remove(Heap *heap);

void Heap_trickle_down(Heap *heap, int i); 
void Heap_bubble_up(Heap *heap, int i);
//size Byteのメモリオブジェクトを入れ替え
void memswap(void *x, void *y, size_t size);

void Heap_init(Heap *heap, size_t data_size, int (*compare)(const void *, const void *))
{
	Vector_init(&(heap->storage), data_size, 0);
	heap->compare = compare;

	return;
}

int Heap_top(Heap *heap, void *data)
{

	if (Heap_size(heap) > 0) {

		if (data != NULL) {
			memcpy(data, Vector_array(&(heap->storage), 0), 
					heap->storage.data_size);
		}

		Heap_remove(heap);

		return 1;
	} else {
		return 0;
	}
}

int Heap_add(Heap *heap, void *data)
{
	if (Vector_push_back(&(heap->storage), data) == 0) {
		return 0;
	}

	Heap_bubble_up(heap, Vector_size(&(heap->storage)) - 1);

	return 1;
}

size_t Heap_size(Heap *heap)
{
	return Vector_size(&(heap->storage));
}

void Heap_clear(Heap *heap)
{
	Vector_clear(&(heap->storage));

	return;
}

//----以下、.hに無い内部関数
void Heap_remove(Heap *heap)
{
	memcpy(Vector_array(&(heap->storage), 0),
			Vector_array(&(heap->storage), Vector_size(&(heap->storage)) - 1),
			heap->storage.data_size);

	Vector_pop_back(&(heap->storage));

	Heap_trickle_down(heap, 0);

	return;
}

//トップダウンにヒープ性を調整
void Heap_trickle_down(Heap *heap, int i)
{
	int j = i; 
	int r, l;

	do {
		i = j;

		j = i;
		r = right_index(i);
		l = left_index(i);

		if (r < Vector_size(&(heap->storage)) &&
				heap->compare(Vector_array(&(heap->storage), r),
					Vector_array(&(heap->storage), j)) < 0) {

			j = r;

		}
		
		if (l < Vector_size(&(heap->storage)) &&
				heap->compare(Vector_array(&(heap->storage), l),
					Vector_array(&(heap->storage), j)) < 0) {
			
			j = l;
		}

		if (j != i) {
			memswap(Vector_array(&(heap->storage), i),
					Vector_array(&(heap->storage), j),
					heap->storage.data_size);
		}

	} while(i != j);

	return;
}

//ボトムアップにヒープ性を調整
void Heap_bubble_up(Heap *heap, int i)
{
	int p = parent_index(i);

	while(i > 0 && heap->compare(Vector_array(&(heap->storage), i),
				Vector_array(&(heap->storage), p)) < 0) {

		memswap(Vector_array(&(heap->storage), i),
				Vector_array(&(heap->storage), p),
				heap->storage.data_size);
		i = p;
		p = parent_index(i);
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
