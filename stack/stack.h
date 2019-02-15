#ifndef __Ei1710_STACK_H
#define __Ei1710_STACK_H

#include <stddef.h>

typedef struct stack_cell{
    void *data;
    struct stack_cell *prev;
}StackCell;

typedef struct stack {
    StackCell *sp;

    size_t data_size;
    size_t stack_size;

    void (*init)(struct stack *, const size_t);
    int (*push)(struct stack *, const void *);
    int (*pop)(struct stack *, void *);
    size_t (*size)(struct stack *);
    void (*clear)(struct stack *);
} Stack;

void initStack(struct stack *s, const size_t data_size);
int Stack_push(struct stack *s, const void *data);
int Stack_pop(struct stack *s, void *data);
size_t Stack_size(struct stack *s);
void Stack_clear(struct stack *s);

#endif
