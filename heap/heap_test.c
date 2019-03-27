#include "heap.h"
#include <stdio.h>
#include <string.h>

typedef int TestType;

int compare(const TestType *x, const TestType *y);

int main()
{
	puts("str");
	char str[256];

	Heap p_que;
	TestType in;
	TestType out;

	Heap_init(&p_que, sizeof(TestType), (int (*)(const void *, const void *))compare);

	do {
		scanf("%s", str);

		if (str[0] == 't') {

			Heap_top(&p_que, &out);
			printf("%d\n", out);

		} else if (str[0] == 'p') {

			Heap_remove(&p_que);

		} else if (str[0] == 'a') {

			scanf("%d", &in);

			Heap_add(&p_que, &in);
		}

	} while(str[0] != 'q');

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
