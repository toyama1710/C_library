#include <stdio.h>

typedef struct _QueCell{
    void *data;
    struct _QueCell *next;
} QueCell;

typedef struct queue {
    QueCell *current;
    QueCell *last;
    
    size_t data_size;
    size_t que_size;

    void (*init)(struct queue *, const size_t);
    int (*enque)(struct queue *, const void *);
    int (*deque)(struct queue *, void *);
    size_t (*size)(struct queue *);
    void (*clear)(struct queue *);
} Queue;

void initQueue(struct queue *q, const size_t data_size);
int Que_enque(struct queue *q, const void *data);
int Que_deque(struct queue *q, void *data);
size_t Que_size(struct queue *q);
void Que_clear(struct queue *q);
