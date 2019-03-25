任意のデータ型を格納可能なStackです。<br>
<br>
Stack_init(&stack, sizeof()) でstackを初期化<br>
stackは初期化するStack構造体へのポインタ<br>
格納するデータ型の大きさを渡して格納データを決定<br>
Stack使用前に必ず呼び出すこと!<br>
<br>
Stack_push(&stack, &data) Stackにデータを格納 dataは格納データへのポインタ<br>
Stack_pop(&stack, &data) Stackからデータを取り出す <br>
取り出したデータをdataに格納 dataが指す領域が十分に大きくない場合動作は不定<br>
<br>
Stack_size(&stack) Stackに格納されているデータの個数を返す
<br>
Stack_clear(&stack) Stackをクリアする<br>
Stackを使ったら必ず呼び出すこと!<br>
<br>
バグ、意見等ありましたら、ご連絡ください。<br>
