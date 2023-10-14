#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1

#define SIZE 256
#define STATUS_0 0 // элемент пуст
#define STATUS_1 1 // элемент заполнен

/* Тип хэширофвания: Сумма кодов первой и последней
букв
Способ разрешения коллизий: Бинарное дерево
*/
typedef struct hash_table {
	
	char name[256];	

	struct hash_table *right;
	struct hash_table *left;

	int status;
		
} hash_table_t;


int find_key(char name[SIZE]) {
	int key = 0;
	for (int i = 0; i < strlen(name); i++) {
		key += name[i];
	}
	return key;
}

void insert_coliz(hash_table_t *root, int hash, int new_key, char value[SIZE]) {
    hash_table_t *tmp = *(&root), *parent = NULL;


	// printf("table: %d|\n", tmp->status);


    int status;
    while (tmp != NULL) {
	// В этом цикле tmp будет иметь адресс, куда нужно будет создать переменную
		int tmp_key = find_key(tmp->name);
		printf("key: %d\n", tmp_key);
		printf("new_key: %d\n", new_key);

        if (tmp_key > new_key) {
			printf("<<<_LEFT_>>>\n");
            parent = tmp;
            status = LEFT;
            tmp = tmp->left;
        } else {
			printf("<<<_RIGHT_>>>\n");
            parent = tmp;
            tmp = tmp->right;
            status = RIGHT;
        }
    }

    tmp = malloc(sizeof(hash_table_t));
    
    if (parent != NULL) {
        // переписываем указатель в parent, т.к. после выделения памяти tmp изменил адресс
        if (status == LEFT) parent->left = tmp;
        else parent->right = tmp;
    }

    tmp->left = NULL;
    tmp->right = NULL;

	strcat(tmp->name, value);
	tmp->status = STATUS_1;

}

void insert(hash_table_t *table_root, int hash, char name[]) {


	hash_table_t *table = &table_root[hash];
	
	
	printf("hash: %d\n", hash);

		if (table->status == STATUS_1) {

			int key = find_key(name);
			printf("table_1: %d|\n", table->status);

			insert_coliz(table, hash, key, name);
		} else {

			// Переносим строку в таблицу
			strcat(table->name, name);
			table->status = STATUS_1;
			table->right = NULL;
			table->left = NULL;
		}

}

void create_hash_table(hash_table_t **table) {
	
	hash_table_t *tmp;
	tmp = malloc(SIZE * sizeof(hash_table_t));


	for (int i = 0; i < SIZE; i++) {
		tmp[i].status = STATUS_0;
	}
	int a;
	while (a != 2) {
		printf("Выберите действие:\n");
		printf("1.Добавить новый элемент в таблицу\n");
		printf("2.Закончить добавление в таблицу\n");
		printf(": ");
		scanf("%d", &a);
		if (a == 1) {
			char name[SIZE];
			printf("Введите строку: "); scanf("%s", name);
			int hash = (name[0] + name[strlen(name) - 1]) % SIZE;

			insert(tmp, hash, name);						
		}
	}
	*table = tmp;
}



int main() {
	hash_table_t *table;
	create_hash_table(&table);

	// printf("table: %s\n", table[227].name);
	// printf("table_coliz_left: %s\n", table[227].left->name);
	// printf("table_coliz_right: %s\n", table[227].right->name);
	// free(table[227].left);
	// free(table[227].right);


	free(table);
	return 0;
}

