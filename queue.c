#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initQueue(struct queue *q, size_t data_size)
{
    q->current = NULL;
    q->last = NULL;

    q->data_size = data_size;
    q->que_size = 0;

    q->init = initQueue;
    q->enque = Que_enque;
    q->deque = Que_deque;
    q->clear = Que_clear;

    return;
}

int Que_enque(struct queue *q, const void *data)
{
    QueCell *new_data = (QueCell *)malloc(sizeof(QueCell));

    if (new_data == NULL) {
        return -1;
    }

    new_data->data = malloc(q->data_size);
    new_data->next = NULL;

    if (new_data->data == NULL) {
        return -1;
    } else {
        memcpy(new_data->data, data, q->data_size);
        ++(q->que_size);
    }
    
    if (q->que_size <= 1) {
        q->current = new_data;
        q->last = new_data;
    } else {
        q->last->next = new_data;
        q->last = new_data;
    }
    

    return 0;
 }

int Que_deque(struct queue *q, void *data)
{
    if (q->que_size > 0) {
        QueCell *next = q->current->next;

        --(q->que_size);
        memcpy(data, q->current->data, q->data_size);

        free(q->current->data);
        free(q->current);
        q->current = next;
    } else {
        return -1;
    }

    return 0;
}

size_t Que_size(struct queue *q)
{
    return q->que_size;
}

void Que_clear(struct queue *q)
{
    while (q->current != NULL) {
        QueCell *next = q->current->next;

        free(q->current->data);
        free(q->current);

        q->current = next;
    }

    initQueue(q, q->data_size);

    return;
}
