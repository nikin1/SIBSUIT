#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// проверка реализована через поиск в глубину
// для работы со стеком 2 функции вынесены в отдельный файл

typedef struct Stack {
    double value;
    struct Stack *prev;
} Stack_t;

Stack_t *Push(Stack_t *last_element, double value);
Stack_t *Pop(Stack_t *last_element);


