#ifndef EI1710_STACK_H
#define EI1710_STACK_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//線形リストでスタックを実装

typedef struct stack_cell{
    void *data; //実データ領域を指す
    struct stack_cell *next; //次セル
}StackCell;

typedef struct stack {
    StackCell *sp; //データの格納、取り出し位置

    size_t data_size; //格納するデータの大きさ
    size_t stack_size; //格納データの個数 (=スタックの大きさ)
} Stack;

//Stack構造体の初期化
//Stackに格納するデータ型は、data_sizeで大きさを指定して決定
//Stackを使う前に必ず呼び出すこと!
void Stack_init(struct stack *s, size_t data_size);

//Stackにデータを格納
//dataは格納データへのポインタ
//エラー:0 正常終了:正数
int Stack_push(struct stack *s, const void *data);

//Stackからデータを取り出す
//dataは取り出したデータの格納領域
//dataが指す領域の大きさが不十分な場合動作は不定
//エラー:0 正常終了:正数
int Stack_pop(struct stack *s, void *data);

//Stackに格納されているデータ数を返す
size_t Stack_size(struct stack *s);

//Stackをクリアする
//Stackを使ったあと必ず呼び出すこと!
void Stack_clear(struct stack *s);

#endif
