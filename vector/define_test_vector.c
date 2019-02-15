#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include "define_vector.c"

Vector(int);

int lineInput(const char *format, ...);

int main()
{
    char str[32];
    int a;
    int_Vector vec;
    init_int_Vector(&vec);
    
    while (scanf("%s", str), strcmp(str, "quit") != 0) {
        
        if (strcmp(str, "push") == 0) {
            scanf("%d", &a);
            vec.push_back(&vec, a);
        }
        else if (strcmp(str, "print") == 0) {
            scanf("%d", &a);
            printf("%d\n", vec.array(&vec, a));
        }
        else if (strcmp(str, "capacity") == 0) {
            printf("%d\n", vec.capacity(&vec));
        }
    }

    vec.clear(&vec);
 
    return 0;
}

int lineInput(const char *format, ...)
{
    va_list ap;
    char buff[64];
    int ret;
    
    va_start(ap, format);
    fgets(buff, sizeof(buff), stdin);
    ret = vsscanf(buff, format, ap);
    va_end(ap);

    return ret;
}
