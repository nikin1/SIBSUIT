#include "graph.h"

Stack_t *Push(Stack_t *last_element, double value) {
    Stack_t *new;
    new = malloc(sizeof(Stack_t));
    assert(new != NULL);
    new->prev = last_element;
    new->value = value;
    return new;
}

Stack_t *Pop(Stack_t *last_element) {
    Stack_t *tmp;
    assert(last_element != NULL);
    tmp = last_element;
    last_element = last_element->prev;
    free(tmp);
    return last_element;
}
