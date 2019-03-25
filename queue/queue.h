#ifndef EI1710_Queue_H
#define EI1710_Queue_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//線形リストでQueueを実装する
//リストの先頭からデータを取り出し、
//リストの末尾にデータを追加していく

typedef struct que_cell{
    void *data;  //実データへのポインタ
    struct que_cell *next;  //次セル
} QueCell;

typedef struct queue {
    QueCell *head; //キューの先頭(データの取り出し位置)
    QueCell *last; //キューの末尾(データの格納位置)

    size_t data_size; //格納データの大きさ
    size_t que_length; //格納データの個数 = キューの大きさ
} Queue;

//Queue構造体の初期化を行う
//q:初期化するQueue構造体へのポインタ
//data_size:格納するデータの大きさ
//Queueを使う前に必ず呼び出すこと！
// ex) int型を格納する場合) Queue_init(&que, sizeof(int));
void Queue_init(struct queue *q, const size_t data_size);

//enque
//q:操作対象のQueueへのポインタ
//data:格納データへのポインタ
//正しく格納できれば正数 エラーが起きたとき0を返す
int Queue_enque(struct queue *q, void *data);

//deque
//q:操作対象のQueueへのポインタ
//data:取り出したデータの格納場所
//キューが空(エラー)のとき0, 正常に取り出したとき正数を返す
//dataが指す領域がデータを格納するのに足らない場合の動作は不定である
int Queue_deque(struct queue *q, void *data);

//キューに格納されているデータ数を返す
size_t Queue_size(struct queue *q);

//Queueをクリアする
//Queueを使い終わったら必ず呼び出すこと！
void Queue_clear(struct queue *q);

#endif
