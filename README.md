汎化したQueueです。<br>
<br>
initQueue(&que, sizeof(data_type)); で初期化します。<br>
&queは初期化するqueueへのポインタ、sizeof()内には格納するデータの型を書いてください。<br>
<br>
Que_enque(&que, &data); でデータを格納します。<br>
Que_deque(&que, &data); でデータを取り出します。<br>
それぞれO(1)です。<br>
queueが空のときにdequeする、データの格納スペースが無い、といったエラーのとき、-1を返します。<br>
正常にデータの格納、取り出しができたときは0を返します。<br>
なお、この二つはque.enque(&que, &data); que.deque(&que, &data); でも等価です。<br>
<br>
Que_clear(&que); que.clear(&que);でqueueをクリアできます。O(N)です。<br>
戻り値はありません。また、メモリリークを防ぐため、使い終わったqueueは必ずクリアしてください。<br>
<br>
Que_size(&que); que.size(&que); でqueueのサイズを取得できます。<br>
C++のSTLのque.empty();のように空判定などにお使いください。<br>
<br>
バグ等発見したら連絡ください。<br>
