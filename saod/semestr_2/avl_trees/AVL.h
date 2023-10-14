#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


// #include "stack.h"

using namespace std;


#define LEFT 0
#define RIGHT 1


typedef struct tree {

    int key;
    int height;

    struct tree* left;
    struct tree* right;
    struct tree* parent;

    // avl_tree(int k) { key = k; left = right = 0; height = 1; }
} avl_tree;


avl_tree *insert(avl_tree *root, int key);
int remove(avl_tree *root, int key);
