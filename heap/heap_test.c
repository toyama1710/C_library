#include "heap.h"
#include <stdio.h>
#include <string.h>

typedef struct {
	int cost;
	int pos;
} TestType;

int compare(const TestType *x, const TestType *y);

int main()
{
	char str[256];

	Heap p_que;
	TestType in;
	TestType out;

	Heap_init(&p_que, sizeof(TestType), (int (*)(const void *, const void *))compare);

	do {
		scanf("%s", str);

		if (str[0] == 't') {
			if (Heap_top(&p_que, &out) == 0) {
				puts("error");
			} else {
				printf("cost:%d pos:%d\n", out.cost, out.pos);
			}

		} else if (str[0] == 'a') {
			scanf("%d %d", &in.cost, &in.pos);

			Heap_add(&p_que, &in);
		} else if (str[0] == 's') {
			printf("%u\n", Heap_size(&p_que));
		}

	} while(str[0] != 'q');

	Heap_clear(&p_que);

	return 0;
}

int compare(const TestType *x, const TestType *y)
{
	if (x->cost > y->cost) {
		return -1;
	} else if (x->cost == y->cost) {
		return 0;
	} else {
		return 1;
	}
}
