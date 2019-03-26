#include <stdio.h>
#include "vector.h"

typedef double TestType;

int main()
{
    Vector vec;
	char str[256];
	TestType a;
	TestType b;
	int indx;

	dbl_Vector_init(&vec, 0);

	do {
		scanf("%s", str);

		if (strcmp(str, "print") == 0) {

			for (int i = 0; i < Vector_size(&vec); i++) {
				printf("%lf ", dbl_Vector_array(&vec, i));
			}
			putchar('\n');

		} else if (str[0] == 'r') {
			printf("index:");
			scanf("%d", &indx);

			b = dbl_Vector_array(&vec, indx);

			printf("%lf\n", b);

		} else if (str[0] == 'w') {
			printf("index:");
			scanf("%d", &indx);

			printf("data:");
			scanf("%lf", &a);

			dbl_Vector_array(&vec, indx) = a;

		} else if (str[0] == 'p') {
			printf("data:");
			scanf("%lf", &b);

			dbl_Vector_push_back(&vec, b);

		} else if (str[0] == 's') {
			printf("%lld\n", Vector_size(&vec));

		} else if (str[0] == 'c') {
			printf("%lld\n", Vector_capacity(&vec));
		}

	} while(str[0] != 'q');

	Vector_clear(&vec);

    return 0;
}
