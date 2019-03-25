#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "queue.h"

typedef struct {
	int x, y;
} TestType;

int finput(FILE *source, const char *format, ...);

int main()
{
	char str[256];
	TestType in;
	TestType out;
	Queue que;
	Queue_init(&que, sizeof(TestType));

	do {
		finput(stdin, "%s", str);

		if (str[0] == 'e') {
			finput(stdin, "%d %d", &in.x, &in.y);

			Queue_enque(&que, &in);

		} else if (str[0] == 'd') {
			if (Queue_deque(&que, &out)) {
				printf("%d %d\n", out.x, out.y);
			} else {
				puts("error");
			}
		}
	} while(str[0] != 'q');

	Queue_clear(&que);

	return 0;
}

int finput(FILE *source, const char *format, ...)
{
    va_list arg;
    char buff[1024];
    int result;

    fgets(buff, sizeof(buff) - 1, source);

    va_start(arg, format);
    result = vsscanf(buff, format, arg);
    va_end(arg);

	return result;
}
