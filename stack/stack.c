#include "stack.h"

StackCell *Stack_cell_create(const void *data, size_t data_size);
void Stack_cell_remove(StackCell *remove);

StackCell *Stack_cell_create(const void *data, size_t data_size)
{
	StackCell *cell = malloc(sizeof(StackCell));

	if (cell == NULL) {
		return NULL;
	}

	cell->data = malloc(sizeof(data_size));

	if (cell->data == NULL) {
		free(cell);
		return NULL;
	}

	memcpy(cell->data, data, data_size);
	cell->next = NULL;

	return cell;
}

void Stack_cell_remove(StackCell *remove)
{
	free(remove->data);
	free(remove);
	
	return;
}

void Stack_init(struct stack *s, size_t data_size)
{
    s->sp = NULL;

    s->data_size = data_size;
    s->stack_size = 0;

    return;
}

int Stack_push(struct stack *s, const void *data)
{
	StackCell *new_cell = Stack_cell_create(data, s->data_size);

	if (new_cell == NULL) {
		return 0;
	}

    new_cell->next = s->sp;
    s->sp = new_cell;

	s->stack_size = s->stack_size + 1;

    return 1;
}

int Stack_pop(struct stack *s, void *data)
{
    if (s->sp == NULL) {
        return 0;
    }

	if (data != NULL) {
		memcpy(data, s->sp->data, s->data_size);
	}

    StackCell *remove = s->sp;
	s->sp = s->sp->next;
	Stack_cell_remove(remove);

    s->stack_size = s->stack_size - 1;

    return 1;
}

size_t Stack_size(struct stack *s)
{
    return s->stack_size;
}

void Stack_clear(struct stack *s)
{
    while (Stack_size(s)) {
		Stack_pop(s, NULL);
    }

    return;
}
