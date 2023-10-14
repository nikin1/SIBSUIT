#include "stack.h"


Stack_t *Push(Stack_t *last_element, double value) {
    Stack_t *new_el;
    new_el = (Stack_t *) malloc(sizeof(Stack_t));
    assert(new_el != NULL);
    new_el->prev = last_element;
    new_el->value = value;
    return new_el;
}

Stack_t *Pop(Stack_t *last_element) {
    Stack_t *tmp;
    assert(last_element != NULL);
    tmp = last_element;
    last_element = last_element->prev;
    free(tmp);
    return last_element;
}
