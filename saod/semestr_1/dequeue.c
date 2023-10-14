#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Dequeue {
  int value;  
  struct Dequeue *next;
  struct Dequeue *prev;
} dequeue_t;


dequeue_t *find_last_el(dequeue_t *last_el) {    
    if (last_el != NULL) {
      while (last_el->next != NULL) {
          last_el = last_el->next;
      }
    }
    return last_el;
}

dequeue_t *find_first_el(dequeue_t *first_el) {
  if (first_el != NULL) {
    while (first_el->prev != NULL) {  
        first_el = first_el->prev;
    }
  }
    return first_el;
}


dequeue_t *push_back(dequeue_t *last_el, int value) {

  last_el = find_last_el(last_el); // если наш элемент не является последним, то мы находим указатель имеенно на последний
  
  dequeue_t *new;
  new = malloc(sizeof(dequeue_t));
  assert(new != NULL);
    
  new->value = value;
  if (last_el != NULL) {
    last_el->next = new;
  }
  new->prev = last_el;
  new->next = NULL;
  return new;
}

dequeue_t *push_front(dequeue_t *root, int value) {

  root = find_first_el(root); // если наш элемент не является первым, то мы находим указатель имеенно на первый
  
  dequeue_t *new;
  new = malloc(sizeof(dequeue_t));
  assert(new != NULL);
    
  new->value = value;
  if (root != NULL) {
    root->prev = new;
  }
  new->next = root;
  new->prev = NULL;
  return new;
}

dequeue_t *pop_front(dequeue_t *root) {
  
  dequeue_t *root_next = NULL;

  root = find_first_el(root);

  if (root->next != NULL) {
      root_next = root->next;
      root_next->prev = NULL; // у следующего элемента исправляем указатель
  }
  
  free(root);

  return root_next;
}

dequeue_t *pop_back(dequeue_t *last) {
  dequeue_t * last_prev = NULL;
    
  last = find_last_el(last);

  if (last->prev != NULL) {    
    last_prev = last->prev;
    last_prev->next = NULL; // у предыдущего элемента исправляем указатель
  }
  
  free(last);
  return last_prev;
}


int main() {
  dequeue_t *A = NULL, *B, *C;
  A = push_back(A, 10);
  assert(A->value == 10);
  B = push_back(A, 11);
  assert(A->next == B);
  C = push_front(B, 9);
  assert(A->prev == C);
  B = pop_back(C); //  память на В очиститься, затем указатель В будет указывать на последний элемент, т.е. А
  assert(B == A);
  C = pop_front(B);
  assert(C == A);
  A = pop_back(A);
  assert(A == NULL);  
  return 0;
}