// #include <stdio.h>
// #include <stdlib.h>

#include "search.h"


// typedef struct queue {
//   int value;  
//   struct queue *next;
//   struct queue *prev;
// } queue_t;


queue_t *find_last_el(queue_t *last_el) {    
    if (last_el != NULL) {
      while (last_el->next != NULL) {
          last_el = last_el->next;
      }
    }
    return last_el;
}

queue_t *find_first_el(queue_t *first_el) {
  if (first_el != NULL) {
    while (first_el->prev != NULL) {  
        first_el = first_el->prev;
    }
  }
    return first_el;
}


queue_t *push_back(queue_t *last_el, int value) {

  last_el = find_last_el(last_el); // если наш элемент не является последним, то мы находим указатель имеенно на последний
  
  queue_t *new;
  new = malloc(sizeof(queue_t));
  assert(new != NULL);
    
  new->value = value;
  if (last_el != NULL) {
    last_el->next = new;
  }
  new->prev = last_el;
  new->next = NULL;
  return new;
}


queue_t *pop_front(queue_t *root) {
  
  queue_t *root_next = NULL;

  root = find_first_el(root);

  if (root->next != NULL) {
      root_next = root->next;
      root_next->prev = NULL; // у следующего элемента исправляем указатель
  }
  
  free(root);

  return root_next;
}

