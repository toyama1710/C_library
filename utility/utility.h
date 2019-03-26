#ifndef EI1710_UTILITY_H
#define EI1710_UTILITY_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

//fscanf()と同じ機能 ただし、変換に失敗した文字がバッファに残らない
int finput(FILE *source, const char *format, ...);

//O(n log n) のソート
int sort(void *base, size_t n_memb, size_t data_size, 
		int (*cmp)(const void *, const void *));

#endif
