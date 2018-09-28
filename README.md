汎化したStackです。<br>
<br>
initStack(&stack, sizeof(data_type));で初期化します。<br>
sizeof()内には、格納するデータ型を書いてください。<br>
<br>
Stack_push(&stack, &data); はstackにdataを格納します。<br>
Stack_pop(&stack, &data); はstackからデータを取り出し、dataに格納します。<br>
なお、stack.push(&stack, &data); stack.pop(&stack, &data);でも呼び出し可です。<br>
<br>
Stack_size(&stack); でstackのサイズを取得します。stack.size(&stack)でもいいです。<br>
<br>
Stack_clear(&stack); でstackをクリアします。stack.clear(&stack)でもいいです。<br>
stackを使い終わったら必ずクリアしてください。<br>
<br>
バグがありましたら、ご連絡ください。<br>
