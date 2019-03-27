#include <stdio.h>
#include <time.h>
#include "utility.h"

#ifndef SIZE
#define SIZE 10
#endif

typedef struct {
	int cost;
	int pos;
} TestType;

int compare(const TestType *x, const TestType *y);

int main()
{
	TestType array[SIZE];

	for (int i = 0; i < SIZE; i++) {
		scanf("%lld %lld", &array[i].cost, &array[i].pos);
	}
	puts("check");

	sort(array, SIZE, sizeof(TestType),
			(int (*)(const void *, const void *))compare);

	for (int i = 0; i < SIZE; i++) {
		printf("%lld %lld\n", array[i].cost, array[i].pos);
	}
}

int compare(const TestType *x, const TestType *y)
{
	if (x->cost > y->cost) {
		return 1;
	} else if (x->cost == y->cost) {
		return 0;
	} else {
		return -1;
	}
}
