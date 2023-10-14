#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

typedef struct Trees {
    int key;
    double value;
    struct Trees *left;
    struct Trees *right;
} trees_t;

trees_t *find(trees_t *root, int x) {
    trees_t *tmp = NULL;
    if (root != NULL) {

        tmp = root;
        while (tmp != NULL) {
            if (x == tmp->key) {
                break;
            } else if (x < tmp->key) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
    }
    
    return tmp;
}

trees_t *insert(trees_t *root, int key, double value) {
    trees_t *tmp = root, *parent = NULL;
    int status;
    while (tmp != NULL) {
// В этом цикле tmp будет иметь адресс, куда нужно будет создать переменную
        if (key < tmp->key) {
            parent = tmp;
            status = LEFT;
            tmp = tmp->left;
        } else {
            parent = tmp;
            tmp = tmp->right;
            status = RIGHT;
        }
    }

    tmp = malloc(sizeof(trees_t));
    
    if (parent != NULL) {
        // переписываем указатель в parent, т.к. после выделения памяти tmp изменил адресс
        if (status == LEFT) parent->left = tmp;
        else parent->right = tmp;
    }

    tmp->left = NULL;
    tmp->right = NULL;
    tmp->key = key;
    tmp->value = value;


    return tmp;
}


int main() {
    // тестирование функций
    trees_t *root = NULL;
    
    root = insert(root, 8, 10.0);
    
    assert(root->value  == 10.0);
    assert(root->key  == 8);

    trees_t *A = insert(root, 3, 11.0);   // А поместится в левый узел 
    trees_t *B = insert(root, 10, 12.0);  // В в правый
    
    assert(B->value  == 12.0);
    assert(A->key  == 3);

    assert(root->left == A);
    assert(root->right == B);
 
    trees_t *find_B = find(root, 10); // ищем В
    assert(B == find_B);

    trees_t *find_A = find(root, 3); // ищем A
    assert(A == find_A);


    free(A);
    free(B);
    free(root);


    return 0;
}