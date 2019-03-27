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

typedef struct {
    Byte *storage; //配列領域

    size_t data_size; //格納データ型のサイズ
    size_t array_size; //格納データの個数
    size_t capacity; //realloc()せずに格納できるデータ数
} Vector;

//vectorの初期化
int Vector_init(Vector *vec, size_t data_size, size_t vec_size);

//vector末尾にデータを追加
int Vector_push_back(Vector *vec, void *data);

//vectorが管理するデータにアクセス
void *Vector_array(Vector *vec, size_t i);

//末尾のデータを削除
int Vector_pop_back(Vector *vec);

//vectorをクリア
void Vector_clear(Vector *vec);

//vectorに格納しているデータの個数を返す
size_t Vector_size(Vector *vec);

//キャパシティを返す
size_t Vector_capacity(Vector *vec);

#endif
