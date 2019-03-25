#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "../utility/utility.h"

typedef int TestType;


int main()
{
	char str[256];
	TestType x;
	Queue que;
	Queue_init(&que, sizeof(TestType));

	do {
		finput(stdin, "%s", str);
		if (str[0] == 'e') {
			finput(stdin, " %d ", &x);

			Queue_enque(&que, &(TestType){x});

		} else if (str[0] == 'd') {
			if (Queue_deque(&que, &x)) {
				printf("%d %d\n", x, Queue_size(&que));
			} else {
				puts("error");
			}
		}
	} while(str[0] != 'q');

	Queue_clear(&que);

	return 0;
}
