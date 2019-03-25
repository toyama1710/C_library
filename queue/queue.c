#include "queue.h"

void Queue_cell_remove(QueCell *remove);
QueCell *Queue_cell_alloc(void *data, size_t data_size);

void Queue_cell_remove(QueCell *remove)
{
	free(remove->data);
	free(remove);

	return;
}

QueCell *Queue_cell_alloc(void *data, size_t data_size)
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

	memcpy(cell->data, data, data_size);
	cell->next = NULL;

	return cell;
}

void Queue_init(struct queue *q, const size_t data_size)
{
	q->head = NULL;
	q->last = NULL;

	q->data_size = data_size;
	q->que_length = 0;

	return;
}

int Queue_enque(struct queue *q, void *data)
{
	QueCell *new_data = Queue_cell_alloc(data, q->data_size);

	if (new_data == NULL) {
		return 0;
	}

	//セル追加
	if (q->que_length <= 0) {
		q->last = new_data;
		q->head = new_data;
	} else {
		q->last->next = new_data;
		q->last = new_data;
	}

	q->que_length = q->que_length + 1;

	return 1;
}

int Queue_deque(struct queue *q, void *data)
{
	if (q->que_length > 0) {

		//データコピー
		if (data != NULL) {
			memcpy(data, q->head->data, q->data_size);
		}

		//セルを解放
		QueCell *remove = q->head;
		q->head = q->head->next;
		Queue_cell_remove(remove);


		q->que_length = q->que_length - 1;

		return 1;
	} else {
		return 0;
	}
}

size_t Queue_size(struct queue *q)
{
	return q->que_length;
}

void Queue_clear(struct queue *q)
{
	//空になるまでdeque()
	while (Queue_size(q)) {
		Queue_deque(q, NULL);
	}

	return;
}
