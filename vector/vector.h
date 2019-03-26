#ifndef EI1710_VECTOR_H
#define EI1710_VECTOR_H

#include "../utility/utility.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char Byte;

//vector実現手法
//memcopy(), memmove()でオブジェクトをコピー
//要素へのアクセスはsizeof(Type) * index バイト分先の要素を見て実現
//あらかじめ大き目に領域を取っておき、キャパシティオーバーしたらrealloc()する

typedef struct vector {
    Byte *storage; //配列領域

    size_t data_size; //格納データ型のサイズ
    size_t array_size; //格納データの個数
    size_t capacity; //realloc()せずに格納できるデータ数
} Vector;

//vectorの初期化
int Vector_init(struct vector *vec, size_t data_size, size_t vec_size);

//vector末尾にデータを追加
int Vector_push_back(struct vector *vec, void *data);

//vectorが管理するデータにアクセス
void *Vector_array(struct vector *vec, size_t i);

//vectorをクリア
void Vector_clear(struct vector *vec);

//vectorに格納しているデータの個数を返す
size_t Vector_size(struct vector *vec);

//キャパシティを返す
size_t Vector_capacity(struct vector *vec);


// int
#define int_Vector_init(Vec, Arr_size) \
	Vector_init(Vec, sizeof(int), Arr_size)

#define int_Vector_push_back(Vec, Data) \
	Vector_push_back(Vec, &(int){Data})

#define int_Vector_array(Vec, Indx) \
	*(int *)Vector_array(Vec, Indx)

//long long
#define llong_Vector_init(Vec, Arr_size) \
	Vector_init(Vec, sizeof(long long), Arr_size)

#define llong_Vector_push_back(Vec, Data) \
	Vector_push_back(Vec, &(long long){Data})

#define llong_Vector_Array(Vec, Indx) \
	*(long long *)Vector_array(Vec, Indx)

//double
#define dbl_Vector_init(Vec, Arr_size) \
	Vector_init(Vec, sizeof(double), Arr_size)

#define dbl_Vector_push_back(Vec, Data) \
	Vector_push_back(Vec, &(double){Data})

#define dbl_Vector_array(Vec, Indx) \
	*(double *)Vector_array(Vec, Indx)

#endif
