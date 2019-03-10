#include <stdio.h>
#include <stdarg.h>
#define DEBUG puts("check");

int format_in(FILE *source, const char *format, ...);

int main()
{
	int a, b, c;
	a = b = c = 1710;
	b++; c++; c++;

	printf("%d %d %d\n", a, b, c);

	format_in(stdin, "%d %d %d", &a, &b, &c);

	printf("%d %d %d\n", a, b, c);

	return 0;
}

int format_in(FILE *source, const char *format, ...)
{
	va_list ap;
	char buff[1024];
	int result;

	fgets(buff, 256, stdin);

	va_start(ap, format);
	result = vsscanf(buff, format, ap);
	va_end(ap);

	return result;
}
