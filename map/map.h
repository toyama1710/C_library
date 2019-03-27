#ifndef EI1710_MAP_H
#define EI1710_MAP_H


//内部実装はAVL木
//また、要素の重複は許さない(キーが被った場合、値を更新)

typedef struct map_node {
	void *data;
	int diff;
	struct map_node *left;
	struct map_node *right;
} MapNode;

typedef MapNode *Map;


void Map_init(Map *map, size_t key_size, size_t data_size,
void rotate(MapNode **node, char mode);


#endif
