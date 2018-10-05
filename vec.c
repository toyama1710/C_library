#include <stdio.h>
#include "test_vector.c"

int main()
{
    Vector vec;

    initVector(&vec, 0, sizeof(int));

    int a;
    while (scanf("%d", &a), a != 0) {
        if (a == -1) {
            scanf("%d", &a);
            vec.push_back(&vec, &a);
        } else if (a == -2) {
            scanf("%d", &a);
            vec.array(&vec, a, &a);

            printf("%d\n", a);
        } else if (a == -3) {
            printf("%zu\n", vec.size(&vec));
        }
    }

    vec.clear(&vec);

    return 0;
}
