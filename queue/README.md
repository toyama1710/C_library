任意のデータ型を格納できるQueueです。<br>
<br>
Queue_init(&que, sizeof(data_type)); で初期化 <br>
&queで指すQueue構造体を初期化し、sizeof(data_type)の大きさを持つデータ型を格納<br>
Queue構造体の使用に先立ち、必ず初期化すること<br>

Queue_enque(&que, &data); でデータを格納<br>
dataは格納するデータの実領域<br>
<br>
Queue_deque(&que, &data); でキューからデータをとりだし、dataが指す領域に格納<br>
dataの領域が十分に大きくない場合の動作は不定<br>

enque, dequeともにO(1)<br>
また、メモリ領域が足りない、キューが空といったエラー時には0を返し、それ以外では正数を返す<br>

<br>
Que_clear(&que) でキューをクリア<br>
キューを使い終わったあとこの関数を呼ばないとメモリリークします<br>
Que_size(&que) でqueueのサイズを取得<br>
<br>
バグ等発見したら連絡ください。<br>
