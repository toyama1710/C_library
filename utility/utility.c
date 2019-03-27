#include "utility.h"

int finput(FILE *source, const char *format, ...)
{
    va_list arg;
    char buff[BUFSIZ];
    int result;

    fgets(buff, sizeof(buff) - 1, source);

    va_start(arg, format);
    result = vsscanf(buff, format, arg);
    va_end(arg);

	return result;
}

//ヒープ性の調整関数
void trickle_down(void *base, size_t i, 
		size_t n_memb, size_t data_size,
		int (*compare)(const void *, const void *));

//ソート本体(ヒープソート)
void sort(void *base, size_t n_memb, size_t data_size, 
		int (*compare)(const void *, const void *))
{
	int i;

	//ヒープ構築
	for (i = n_memb / 2; i >= 0; i--) {
		trickle_down(base, i, n_memb, data_size, compare);
	}

	//最大のものを末尾へ移動し、ヒープを再構築
	for (i = n_memb - 1; i >= 1; i--) {
		memswap((unsigned char *)base,
				(unsigned char *)base + (data_size * i), data_size);

		trickle_down(base, 0, i, data_size, compare);
	}

	return;
}

//上のソートに必要なヒープ性を保つ関数
//みんなのデータ構造 p181 参考
void trickle_down(void *base, size_t i, 
		size_t n_memb, size_t data_size,
		int (*compare)(const void *, const void *))
{
	size_t l, r;
	size_t j = i;
	unsigned char *arr = base;
	
	do {
		i = j;

		r = 2 * i + 2;
		l = 2 * i + 1;

		if (l < n_memb &&
				compare(arr + l * data_size, arr + j * data_size) > 0) {
			j = l;
		}

		if (r < n_memb &&
				compare(arr + r * data_size, arr + j * data_size) > 0) {
			j = r;
		}

		if (i != j) {
			memswap(arr + i * data_size, arr + j * data_size, data_size);
		}

	} while (i != j);

	return;
}

void memswap(void *x, void *y, size_t size)
{
	if (x != y) {
		while (size--) {
			*((unsigned char *)x + size) ^= *((unsigned char *)y + size);
			*((unsigned char *)y + size) ^= *((unsigned char *)x + size);
			*((unsigned char *)x + size) ^= *((unsigned char *)y + size);
		}
	}

	return;
}

//比較関数群
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
