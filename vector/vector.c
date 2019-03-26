#include "vector.h"

//vectorの初期化
int Vector_init(struct vector *vec, size_t data_size, size_t vec_size)
{
	vec->data_size = data_size;
	vec->capacity = 0;
	vec->array_size = 0;

	if (vec_size > 0) {
		vec->storage = calloc(vec_size, data_size);
		
		if (vec->storage == NULL) {
			return 0;
		} else {
			vec->capacity = vec_size;
			vec->array_size = vec_size;
		}
	} else {
		vec->storage = NULL;
	}

	return 1;
}

//vector末尾にデータを追加
int Vector_push_back(struct vector *vec, void *data)
{
	size_t indx = vec->array_size;
	size_t new_capacity = max(vec->capacity + 1, vec->capacity * 2);
	Byte *new_storage;


	//配列の再確保
	if (indx >= vec->capacity) {
		new_storage = realloc(vec->storage,
				new_capacity * vec->data_size);

		if (new_storage == NULL) {
			return 0;
		} else {
			vec->storage = new_storage;
			vec->capacity = new_capacity;
		}

	}

	memcpy(vec->storage + (indx * vec->data_size), 
			data, 
			vec->data_size);

	vec->array_size = vec->array_size + 1;

	return 1;
}

//vectorが管理するデータにアクセス
void *Vector_array(struct vector *vec, size_t i)
{
	if (i >= vec->array_size || i < 0) {
		return NULL;
	} else {
		return (vec->storage + (vec->data_size * i));
	}
}

//vectorをクリア
void Vector_clear(struct vector *vec)
{
	free(vec->storage);

	Vector_init(vec, vec->data_size, 0);

	return;
}

//vectorに格納しているデータの個数を返す
size_t Vector_size(struct vector *vec)
{
	return vec->array_size;
}

//キャパシティを返す
size_t Vector_capacity(struct vector *vec)
{
	return vec->capacity;
}
