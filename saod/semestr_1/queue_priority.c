#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Queue {
  int value;
  int priority;
  struct Queue *next;
  struct Queue *prev;
} queue_t;


queue_t *enqueue(queue_t *last_el, int value, int priority) { // push
  queue_t *new;
  new = malloc(sizeof(queue_t));
  assert(new != NULL);
  new->priority = priority;
  new->value = value;

  last_el->next = new;
  new->prev = last_el;
  new->next = NULL;
  return new;
}

queue_t *create_queue(int value, int priority) { // push
  queue_t *root;
  root = malloc(sizeof(queue_t));
  assert(root != NULL);
  root->priority = priority;
  root->value = value;
  root->prev = NULL;
  return root;
}

queue_t *dequeue(queue_t *root) {   // pop
  queue_t *tmp = root;
  int max_priority = root->priority;
  while (tmp != NULL) {
    if (max_priority < tmp->priority) {
      max_priority = tmp->priority; // находим максимальный приоритет
    }
    tmp = tmp->next;
  }
  // now tmp = NULL
  tmp = root;
  while (tmp != NULL) {
    if (tmp->priority == max_priority) {
      if (tmp->next && tmp->prev) {
          tmp->prev->next = tmp->next; // соединяем предыдущий со след
      }
      else if (tmp->prev == NULL) {
        root = tmp->next; // обновляем указатель root в случае если удаляем первый эл
      } 
      else if (tmp->next == NULL) {
          tmp->prev->next = NULL;
      }
      free(tmp);
      break;
    }
    tmp = tmp->next;
  }
  return root;
}


int main() {
  // тесты по очередям с приоритетом
  queue_t *root = create_queue(10, 0); // создаем 1-ый эл
  queue_t *tmp = enqueue(root, 15, 0); // создаем 2-ой
  assert(tmp->value == 15);   // тестим значения
  assert(root->value == 10);
  assert(root->next == tmp);   // проверям, что они правильго соединены
  queue_t *tmp2 = enqueue(tmp, 20, 1); // создаем 3-ий эл
  assert(tmp->next == tmp2);
  root = dequeue(root);
  assert(tmp->next == NULL); // Последний эл удалился
  root = dequeue(root);
  // printf("value: %d\n", root->value);
  assert(root->value == 15); // смотрим что первый эл удалился

  return 0;
}
