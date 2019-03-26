#include <stdio.h>
#include "vector.h"

typedef int TestType;

int main()
{
    Vector vec;
	char str[256];
	TestType a;
	TestType b;

    Vector_init(&vec, sizeof(TestType), 0);

	do {
		scanf("%s", str);

		if (strcmp(str, "print") == 0) {

			for (int i = 0; i < Vector_size(&vec); i++) {
				printf("%d ", *(TestType *)Vector_array(&vec, i));
			}
			putchar('\n');

		} else if (str[0] == 'r') {
			printf("index:");
			scanf("%d", &a);

			b = *(TestType *)Vector_array(&vec, a);

			printf("%d\n", b);

		} else if (str[0] == 'w') {
			printf("index:");
			scanf("%d", &a);

			printf("data:");
			scanf("%d", &b);

			*(TestType *)Vector_array(&vec, a) = b;

		} else if (str[0] == 'p') {
			printf("data:");
			scanf("%d", &b);

			Vector_push_back(&vec, &b);

		} else if (str[0] == 's') {
			printf("%d\n", Vector_size(&vec));

		} else if (str[0] == 'c') {
			printf("%d\n", Vector_capacity(&vec));
		}

	} while(str[0] != 'q');

	Vector_clear(&vec);

    return 0;
}
