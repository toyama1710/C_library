#include "queue.h"

QueCell *Queue_cell_alloc(va_list data, size_t data_size)
{
	QueCell *cell = malloc(sizeof(QueCell));

	if (cell == NULL) {
		return NULL;
	}

	cell->data = malloc(data_size);

	if (cell->data == NULL) {
		free(cell);
		return NULL;
	}

	vmemcpy(cell->data, data);

	return 0;
}

void Queue_init(struct queue *q, const size_t data_size)
{
	q->head = NULL;
	q->last = NULL;

	q->data_size = data_size;
	q->que_length = 0;

	return;
}

int Queue_enque(struct queue *q, ...);
{
	va_list data;
	QueCell *new_data;

	//セル生成
	va_start(data, q);
	new_data = Queue_cell_alloc(data);
	va_end(data);

	if (new_data == NULL) {
		return 0;
	}

	//セル追加
	if (q->last == NULL) {
		q->last = new_data;
		q->head = new_data;
	} else {
		q->last->next = new_data;
		q->last = new_data;
	}

	q->que_length = q->que_length + 1;

	return 0;
}

int Que_deque(struct queue *q, void *data)
{
	if (q->que_size > 0) {
		//データコピー
		
		if (data != NULL) {
			memcpy(data, q->head->data, q->data_size);
		}

		//セルを解放し、ポインタ繋ぎ変え
		QueCell *next = q->head->next;
		free(q->head->data);
		free(q->head);
		q->head = next;

		q->que_length = q->que_length - 1;

		return 1;
	} else {
		return 0;
	}
}

size_t Que_size(struct queue *q)
{
	return q->que_length;
}

void Que_clear(struct queue *q)
{
	//空になるまでdeque()
	while (Queue_size(q)) {
		Queue_deque(q, NULL);
	}

	return;
}
