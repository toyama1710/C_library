#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char __Byte; //Byte型だと既存の型名と被るかもしれないので

//-------
//1バイトずつmemcopy(), memmove()などでデータを格納
//要素へのアクセスはsizeof(Type) * index バイト分先の要素を見て実現
//あらかじめ大き目に領域を取っておき、キャパシティオーバーしたらrealloc()する
//-------
typedef struct vector {
    __Byte *storage;

    size_t data_size;
    size_t vec_size;
    size_t capacity;

    int  (*push_back)(struct vector *vec, void *data);
    int  (*array)(struct vector *vec, size_t i, void *data);
    void (*clear)(struct vector *vec);
    size_t (*size)(struct vector *vec);
} Vector;

int initVector(struct vector *vec, size_t vec_size, size_t data_size);
int Vec_push_back(struct vector *vec, void *data);
int Vec_array(struct vector *vec, size_t i, void *data);
void Vec_clear(struct vector *vec);
size_t Vec_size(struct vector *vec);

int initVector(struct vector *vec, size_t vec_size, size_t data_size)
{
    vec->data_size = data_size;
    vec->vec_size = 0;
    vec->capacity = vec_size;

    vec->storage = (__Byte*)malloc(data_size * vec_size);
    if (vec->storage == NULL) {
        return -1;
    }

    vec->push_back = Vec_push_back;
    vec->array = Vec_array;
    vec->clear = Vec_clear;
    vec->size = Vec_size;

    return 0;
}

int Vec_push_back(struct vector *vec, void *data)
{
    if (Vec_size(vec) + 1 <= vec->capacity) {
        memcpy(vec->storage + (vec->data_size * Vec_size(vec)), data, vec->data_size); 
        ++(vec->vec_size);

        return 0;
    } else {
        size_t new_capacity = (vec->capacity * 2 > vec->capacity + 1 ? vec->capacity * 2 : vec->capacity + 1);
        void *ptr;

        ptr = realloc(vec->storage, vec->data_size * new_capacity);

        if (ptr == NULL) {
            return -1;
        }

        memcpy(vec->storage + (vec->data_size * Vec_size(vec)), data, vec->data_size); 

        ++(vec->vec_size);
        vec->storage = ptr;
        vec->capacity = new_capacity;

        return 0;
    }
}

int Vec_array(struct vector *vec, size_t i, void *data)
{
    if (i < Vec_size(vec)) {
        memcpy(data, vec->storage + (vec->data_size * i), vec->data_size);
        return 0;
    } else {
        return -1;
    }
}

void Vec_clear(struct vector *vec)
{
    free(vec->storage);

    return;
}

size_t Vec_size(struct vector *vec)
{
    return vec->vec_size;
}
