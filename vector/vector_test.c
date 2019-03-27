#include <stdio.h>
#include "vector.h"

typedef struct {
	int to, from;
	int cost;
} TestType;

int main()
{
    Vector vec;
	char str[256];
	TestType a;
	TestType b;
	int indx;

	Vector_init(&vec, sizeof(TestType), 0);

	do {
		scanf("%s", str);

		if (strcmp(str, "print") == 0) {

			for (int i = 0; i < Vector_size(&vec); i++) {
				TestType tmp = *(TestType *)Vector_array(&vec, i);
				printf("to: %d, from: %d, cost: %d\n", 
						tmp.to, tmp.from, tmp.cost);
			}

		} else if (str[0] == 'r') {
			printf("index:");
			scanf("%d", &indx);

			TestType tmp = *(TestType *)Vector_array(&vec, indx);

			printf("to: %d, from: %d, cost: %d\n", 
					tmp.to, tmp.from, tmp.cost);

		} else if (str[0] == 'w') {
			printf("index:");
			scanf("%d", &indx);

			printf("data:");
			scanf("%d %d %d", &a.to, &a.from, &a.cost);

			*(TestType *)Vector_array(&vec, indx) = a;

		} else if (str[0] == 'p') {
			printf("data:");
			scanf("%d %d %d", &a.to, &a.from, &a.cost);

			Vector_push_back(&vec, &a);

		} else if (str[0] == 's') {
			printf("%lld\n", Vector_size(&vec));

		} else if (str[0] == 'c') {
			printf("%lld\n", Vector_capacity(&vec));
		}

	} while(str[0] != 'q');

	Vector_clear(&vec);

    return 0;
}
