#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "stack.c"

typedef char TestType;

int finput(FILE *source, const char *format, ...);

int main()
{
	char str[256];
	TestType in;
	TestType out;
	Stack st;
	Stack_init(&st, sizeof(TestType));

	do {
		finput(stdin, "%s", str);

		if (strcmp(str, "push") == 0) {
			finput(stdin, "%c", &in);

			Stack_push(&st, &in);

		} else if (strcmp(str, "pop") == 0) {
			if (Stack_pop(&st, &out)) {
				printf("%c\n", out);
			} else {
				puts("error");
			}
		}
	} while(str[0] != 'q');

	Stack_clear(&st);

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
