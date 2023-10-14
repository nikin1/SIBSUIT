#include "AVL.h"

int height(avl_tree* p) {
    
    return p ? p->height: 0;
}

int bfactor(avl_tree *p) {

    return height(p->right) - height(p->left);
}

void fixheight(avl_tree *p) {
    int h_left = height(p->left);
    int h_right = height(p->right);
    
    p->height = (h_left > h_right ? h_left : h_right) + 1;
}



avl_tree* rotate_right(avl_tree* alfa) {

    // NEED to check parent ptr

    avl_tree* beta = alfa->right;
    
    //  а если бета лефт не сущ
    if (beta->left) {
        avl_tree* beta_left = beta->left;
        alfa->right = beta_left;
        alfa->right->parent = alfa; // check
    } else {
        alfa->right = NULL;
    }

    beta->left = alfa;
    
    beta->parent = alfa->parent;
    alfa->parent = beta;
    

    fixheight(alfa);
    fixheight(beta);

    return beta;
}

avl_tree* rotate_left(avl_tree* alfa) {

    // NEED to check parent ptr

    avl_tree* beta = alfa->left;
    
    //  а если бета лефт не сущ
    if (beta->right) {
        avl_tree* beta_right = beta->right;
        alfa->left = beta_right;
        alfa->left->parent = alfa; // check
    } else {
        alfa->left = NULL;
    }

    beta->right = alfa;
    
    beta->parent = alfa->parent;
    alfa->parent = beta;
    

    fixheight(alfa);
    fixheight(beta);

    return beta;
}


avl_tree* rotate_big_right(avl_tree* alfa) {

    // NEED to check parent ptr

    avl_tree* beta = alfa->right;
    avl_tree* gamma = beta->left;
    avl_tree* gamma_left = gamma->left;
    avl_tree* gamma_right = gamma->right;

    gamma->left = alfa;
    gamma->right = beta;

    gamma->parent = alfa->parent;
    alfa->parent = gamma;
    beta->parent = gamma;


    alfa->right = gamma_left;
    beta->left = gamma_right;

    if (alfa->right) alfa->right->parent = alfa;
    if (beta->left) beta->left->parent = beta;


    fixheight(alfa);
    fixheight(beta);
    fixheight(gamma);

    return gamma;
}


avl_tree* rotate_big_left(avl_tree* alfa) {

    avl_tree* beta = alfa->left;
    avl_tree* gamma = beta->right;
    avl_tree* gamma_left = gamma->left;
    avl_tree* gamma_right = gamma->right;

    gamma->left = beta;
    gamma->right = alfa;

    gamma->parent = alfa->parent;
    alfa->parent = gamma;
    beta->parent = gamma;


    alfa->left = gamma_right;
    beta->right = gamma_left;

    if (beta->right) beta->right->parent = beta;
    if (alfa->left) alfa->left->parent = alfa;


    fixheight(alfa);
    fixheight(beta);
    fixheight(gamma);

    return gamma;
}



// Лучше сначала потестить, потом уже писать аналогичные функции
/* avl_tree* big_rotate_right(avl_tree* alfa) {

}
*/




void balance(avl_tree *alfa) {

    // NEED to check parent ptr 

    fixheight(alfa);
    cout << "\n\t\t\tTest to balance -- ";
    cout << "check_Key: " << alfa->key << " -- ";


    if ( bfactor(alfa) == 2) {

        cout << "RIGHT ROTATE...";

        avl_tree* beta = alfa->right;

        // Малое вращение
        if ( bfactor(beta) == 0 || bfactor(beta) == 1 ) {
            cout << " -- small\n";
            rotate_right(alfa);
        } else {
            cout << " -- big\n";
        }


    } else if ( bfactor(alfa) == -2 ) {
        cout << "LEFT ROTATE...\n";
    } else {
        cout << "balance not need\n"; 
    }


}

void traversal_to_balance(avl_tree *alfa) {
    // идем до корня

    avl_tree *parent = alfa->parent;

    balance(alfa);  // А изменится ли дерево в этой функции? !!!!

    if (parent != NULL) traversal_to_balance(parent);

}

avl_tree *insert(avl_tree *root, int key) {
    avl_tree *tmp = root;
    avl_tree *parent = NULL;
    
    int status;
    while (tmp != NULL) {
// В этом цикле tmp будет иметь адресс, куда нужно будет создать переменную
        if (key < tmp->key) {
            parent = tmp;
            status = LEFT;

            tmp = tmp->left;
        } else {
            parent = tmp;
            status = RIGHT;

            tmp = tmp->right;
        }
    }

    // cout << "<<>>>\n";
    tmp = (avl_tree*)malloc(sizeof(avl_tree));
    // переписываем указатель в parent, т.к. после выделения памяти tmp изменил адресс

    if (parent != NULL) {        
        
        if (status == LEFT) parent->left = tmp;
        else parent->right = tmp;

        tmp->parent = parent;
    }    

    tmp->left = NULL;
    tmp->right = NULL;
    
    tmp->key = key;
    tmp->height = 1;


    // tmp->value = value;




    // Need to balance
    
    if (parent != NULL) {
        cout << "\nkey: " << tmp->key << " -- ";
        cout << "parent_key: " << parent->key;

        traversal_to_balance(parent);
    }


    return tmp;
}

avl_tree *search_element(avl_tree *tmp, int key) {

    if (tmp == NULL) {
        return NULL;
    }


    if (key < tmp->key) {
        search_element(tmp->left, key);
    } else if (key > tmp->key) {
        search_element(tmp->right, key);
    } else if (key == tmp->key) {
        cout << "KEY == " << tmp->key << "\n";
        return tmp;
    }

    return NULL;
}

int remove(avl_tree *root, int key) {

    // avl_tree *tmp = search_element(root, key);
    
    // if (tmp == NULL) {
    //     cout << "NULL\n";
    //     return 0;
    // }

    avl_tree *tmp = root;

    while (tmp != NULL) {

        if (key < tmp->key) {
            tmp = tmp->left;
        } else if (key > tmp->key) {
            tmp = tmp->right;
        } else {
            break;
        }
    
    }
    cout << "FREE\n";
    if (tmp == NULL) {
        cout << "NULL\n";
        return 0;
    }


    
    avl_tree *parent = tmp->parent; 

    // теперь рассмматриваем 3 случая
    if (tmp->left == NULL && tmp->right == NULL) {

        if (parent != NULL) {
            if (parent->left == tmp) parent->left = NULL;                
            else                     parent->right = NULL;                    
        }

    }

    else if (tmp->left == NULL || tmp->right == NULL) {
        
        avl_tree *child = NULL;

        if (tmp->left == NULL) child = tmp->right;
        else                   child = tmp->left;

        

        if (parent != NULL) {
            if (parent->left == tmp) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            child->parent = parent;
            
        }
    } 

    else {
        // need find the next element after tmp

        avl_tree *next_el = tmp->right;

        // maybe the next el < tmp->right
        while (next_el->left != NULL) {
            next_el = next_el->left;
        }

        // this next_el doesn't have child !!!!

        if (parent->left == tmp) {
            parent->left = next_el;
        }
        else {
            parent->right = next_el;
        }
        
        next_el->left = tmp->left;
        if (next_el != tmp->right) next_el = tmp->right;

        next_el->parent = parent;

    }

    free(tmp);
    

    if (parent != NULL) {
        traversal_to_balance(parent);
    }


    return 1;
}