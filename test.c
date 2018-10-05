#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int line_input(const char *format, ...);
int input(const char *format, size_t buff, ...);

int main()
{
    int a, b;
    int i = 0;

    do {
        printf("%d time\n", i);

        line_input("%d %d", &a, &b);
        //scanf("%d %d", &a, &b);
        //input("%d %d", 1024, &a, &b);

        printf("%d %d\n", a, b);

        ++i;
    } while (a != 0);

    return 0;
}

int line_input(const char *format, ...)
{
    char buff[1024];
    int ret;

    fgets(buff, sizeof(buff), stdin);

    va_list ap;
    va_start(ap, format);
    ret = vsscanf(buff, format, ap);
    va_end(ap);

    return ret;
}

int input(const char *format, size_t buff_size, ...)
{
    char *buff = (char *)malloc(buff_size);
    int ret;

    fgets(buff, buff_size, stdin);

    va_list ap;
    va_start(ap, buff_size);
    ret = vsscanf(buff, format, ap);
    va_end(ap);

    free(buff);

    return ret;
}
