#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initStack(struct stack *s, const size_t data_size)
{
    s->sp = NULL;

    s->data_size = data_size;
    s->stack_size = 0;

    s->init = initStack;
    s->push = Stack_push;
    s->pop = Stack_pop;
    s->size = Stack_size;
    s->clear = Stack_clear;

    return;
}

int Stack_push(struct stack *s, const void *data)
{
    StackCell *new_data = (StackCell *)malloc(sizeof(StackCell));

    if (new_data == NULL) {
        return -1;
    }

    new_data->data = malloc(s->data_size);

    if (new_data->data == NULL) {
        return -1;
    } else {
        memcpy(new_data->data, data, s->data_size);
        ++(s->stack_size);
    }
    
    new_data->prev = s->sp;
    s->sp = new_data;

    return 0;
}

int Stack_pop(struct stack *s, void *data)
{
    if (s->sp == NULL) {
        return -1;
    }

    memcpy(data, s->sp->data, s->data_size);

    StackCell *prev = s->sp->prev;
    --(s->stack_size);

    free(s->sp->data);
    free(s->sp);
    
    s->sp = prev;

    return 0;
}

size_t Stack_size(struct stack *s)
{
    return s->stack_size;
}

void Stack_clear(struct stack *s)
{
    while (s->sp != NULL) {
        StackCell *prev = s->sp->prev;

        free(s->sp->data);
        free(s->sp);

        s->sp = prev;
    }

    initStack(s, s->stack_size);

    return;
}
