#include <stdio.h>
#include <stdarg.h>
#include <string.h>

//引数リストorgが持つデータをcpにsizeバイト分コピー
//おおよそ memcpy() と同じ
void *vmemcpy(void *cp, va_list org, size_t size); 

//fscanf()と同じ機能 ただし、変換に失敗した文字がバッファに残らない
int finput(FILE *source, const char *format, ...);
