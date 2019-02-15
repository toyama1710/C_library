#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
//マクロでvectorのコードを展開して提供する邪悪な手法

#define Vector(Type)                                                    \
    typedef struct Type##vector {                                       \
        Type *storage;                                                  \
        size_t vec_size;                                                \
        size_t vec_capacity;                                            \
                                                                        \
        int (*push_back)(struct Type##vector *vec, Type data);          \
        Type (*array)(struct Type##vector *vec, size_t i);              \
        void (*clear)(struct Type##vector *vec);                        \
        size_t (*size)(struct Type##vector *vec);                       \
        size_t (*capacity)(struct Type##vector *vec);                   \
    } Type##_Vector;                                                     \
                                                                        \
    void init_##Type##_Vector(struct Type##vector *vec);                \
    int vector_##Type##_push_back(struct Type##vector *vec, Type data); \
    Type vector_##Type##_array(struct Type##vector *vec, size_t i);     \
    void vector_##Type##_clear(struct Type##vector *vec);               \
    size_t vector_##Type##_size(struct Type##vector *vec);              \
    size_t vector_##Type##_capacity(struct Type##vector *vec);          \
                                                                        \
                                                                        \
    void init_##Type##_Vector(struct Type##vector *vec)                        \
    {                                                                   \
        vec->storage = NULL;                                            \
        vec->vec_size = 0;                                              \
        vec->vec_capacity = 0;                                          \
                                                                        \
        vec->push_back = vector_##Type##_push_back;                     \
        vec->array = vector_##Type##_array;                             \
        vec->clear = vector_##Type##_clear;                             \
        vec->size  = vector_##Type##_size;                              \
        vec->capacity = vector_##Type##_capacity;                       \
        return;                                                         \
    }                                                                   \
                                                                        \
    int vector_##Type##_push_back(struct Type##vector *vec, Type data)  \
    {                                                                   \
    if (vector_##Type##_size(vec) < vector_##Type##_capacity(vec)) {    \
        vec->storage[vector_##Type##_size(vec)] = data;                 \
                                                                        \
        ++(vec->vec_size);                                              \
                                                                        \
        return 0;                                                       \
    } else {                                                            \
        size_t new_capacity = (vector_##Type##_capacity(vec) + 1 > vector_##Type##_capacity(vec) * 2 ? \
                               vector_##Type##_capacity(vec) + 1 : vector_##Type##_capacity(vec) * 2); \
        Type *ptr = realloc(vec->storage, sizeof(Type) * new_capacity); \
                                                                        \
        if(ptr == NULL) {                                               \
            return -1;                                                  \
        }                                                               \
                                                                        \
        vec->vec_capacity = new_capacity;                               \
        vec->storage = ptr;                                             \
        vec->storage[vector_##Type##_size(vec)] = data;                 \
        ++(vec->vec_size);                                              \
                                                                        \
        return 0;                                                       \
    }                                                                   \
    }                                                                   \
                                                                        \
     Type vector_##Type##_array(struct Type##vector *vec, size_t i)     \
     {                                                                  \
         return vec->storage[i];                                        \
     }                                                                  \
                                                                        \
     void vector_##Type##_clear(struct Type##vector *vec)               \
     {                                                                  \
         free(vec->storage);                                            \
         return;                                                        \
     }                                                                  \
                                                                        \
     size_t vector_##Type##_size(struct Type##vector *vec)              \
     {                                                                  \
         return vec->vec_size;                                          \
     }                                                                  \
                                                                        \
     size_t vector_##Type##_capacity(struct Type##vector *vec)          \
     {                                                                  \
         return vec->vec_capacity;                                      \
     }

#endif
