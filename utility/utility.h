#ifndef EI1710_UTILITY_H
#define EI1710_UTILITY_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//fscanf()と同じ機能 ただし、変換に失敗した文字がバッファに残らない
int finput(FILE *source, const char *format, ...);

#endif
