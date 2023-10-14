#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef struct queue {
  int value;  
  struct queue *next;
  struct queue *prev;
} queue_t;

queue_t *pop_front(queue_t *root);
queue_t *push_back(queue_t *last_el, int value);
queue_t *find_first_el(queue_t *first_el);
queue_t *find_last_el(queue_t *last_el);
