汎化したStackです。<br>
<br>
initStack(&stack, sizeof())でstackを初期化します。<br>
sizeof()内にstackに格納するデータ型を書いてください。<br>
<br>
Stack_push(&stack, &data); Stack_pop(&stack, &data);がpush, popにあたります。<br>
dataをstackに格納し、取り出したデータをdataに入れます。<br>
<br>
Stack_size(&stack)またはstack.size(&stack)でstackに格納しているデータ数を返します。<br>
<br>
Stack_clear(&stack)またはstack.clear(&stack)でstackに格納したデータを開放します。<br>
stackを使い終わったら必ずクリアしてください。<br>
<br>
バグ、意見等ありましたら、ご連絡ください。<br>
