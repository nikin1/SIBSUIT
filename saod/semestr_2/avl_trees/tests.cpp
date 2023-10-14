#include "AVL.h"

int main() {

    // Need to test
    avl_tree *A = insert(NULL, 3);


    avl_tree *B = insert(A, 2);
    
    assert(B == A->left);

    avl_tree *C = insert(A, 7);

    assert(C == A->right);
    assert(C->key == 7);

    avl_tree *D = insert(A, 1);

    assert(D == B->left);

    assert(C == A->right);
    assert(B == A->left);


    avl_tree *E = insert(A, 8);
    avl_tree *F = insert(A, 4);
    avl_tree *H = insert(A, 9);


    assert(C->right->right->key == 9);

    remove(A, 1);

    // free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);
    free(H);


    // Testing small right rotate
    // avl_tree *A = insert(NULL, 1);
    // avl_tree *B = insert(A, 2);
    // avl_tree *C = insert(A, 3);

    // assert(A->parent == B);
    // assert(B->left == A);
    // assert(B->right == C);
    // assert(C->parent == B);
    // assert(C->key == 3);
    // assert(C->left == NULL);
    // assert(C->right == NULL);
    // assert(A->left == NULL);
    // assert(A->right == NULL);


    // free(A);
    // free(B);
    // free(C);


    // Было бы замечательно написать функцию по выводу дерева
    // А то писать функции всех проверок не хочется 
    // Ох, гораздо проще было бы написать еще парочку проверок, чем эту
    // функцию.

    cout << "Testing SUCCES...!\n";
    return 0;
}

