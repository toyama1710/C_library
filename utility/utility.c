#include "utility.h"

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

//”äŠrŠÖ”ŒQ
int int_compare(int *x, int *y)
{
	if (*x > *y) {
		return 1;
	} else if (*x == *y) {
		return 0;
	} else {
		return -1;
	}
}

int llong_compare(long long *x, long long *y)
{
	if (*x > *y) {
		return 1;
	} else if (*x == *y) {
		return 0;
	} else {
		return -1;
	}
}

int dbl_compare(double *x, double *y)
{
	if (*x > *y) {
		return 1;
	} else if (*x < *y) {
		return -1;
	} else {
		return 0;
	}
}

int int_greater_compare(int *x, int *y)
{
	if (*x > *y) {
		return -1;
	} else if (*x == *y) {
		return 0;
	} else {
		return 1;
	}
}

int llong_greater_compare(long long *x, long long *y)
{
	if (*x > *y) {
		return -1;
	} else if (*x == *y) {
		return 0;
	} else {
		return 1;
	}
}

int dbl_greater_compare(double *x, double *y)
{
	if (*x > *y) {
		return -1;
	} else if (*x < *y) {
		return 1;
	} else {
		return 0;
	}
}
