#include "heap.h"
#include <stdio.h>
#include <string.h>

typedef int TestType;

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
				printf("%d\n", out);
			}

		} else if (str[0] == 'a') {
			scanf("%d", &in);

			Heap_add(&p_que, &in);
		}

	} while(str[0] != 'q');

	Heap_clear(&p_que);

	return 0;
}

int compare(const TestType *x, const TestType *y)
{
	if (*x > *y) {
		return 1;
	} else if (*x == *y) {
		return 0;
	} else {
		return -1;
	}
}
