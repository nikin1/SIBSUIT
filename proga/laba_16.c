#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list_1 {
    struct list_1 *next;
    int value;    
} list_1_t;

typedef struct list_2 {
    struct list_2 *next;
    struct list_2 *prev;

    struct list_1 *list;     

} list_2_t;

list_1_t *push_list_1(list_1_t *end, int value) {
    list_1_t *new;
    new = malloc(sizeof(list_1_t));
    assert(new != NULL);

    if (end != NULL) {
        end->next = new;
    }
    new->next = NULL;
    new->value = value;
    return new;
}

list_2_t *push_list_2(list_2_t *end) {
    list_2_t *new;
    new = malloc(sizeof(list_2_t));
    assert(new != NULL);

    if (end != NULL) {
        end->next = new;
    }
    new->next = NULL;
    new->prev = end;

    return new;
}

list_1_t *pop_list_1(list_1_t *A, list_1_t *head) {
    list_1_t *tmp = NULL;
    if (A != NULL) {
        tmp = head;
        while (tmp->next != A) {
            tmp = tmp->next;
        }
        tmp->next = A->next;
        free(A);
    }
    return tmp;
}

list_2_t *pop_list_2(list_2_t *A) {
    list_2_t *end = NULL;
    if (A != NULL) {
        end = A->prev;
        if (end != NULL) end->next = NULL;
        free(A);
    }
    return end;
}


int create_struct(list_1_t **list1, list_2_t **list2) {

    list_2_t *LIST2 = NULL;
    list_1_t *LIST1 = NULL;


    int N = 0;
    while (1) {
        int a;
        printf("value: ");
        scanf("%d", &a);
        // создаю 1 структуру, создаю вторую и соединяю
        LIST2 = push_list_2(LIST2);
        LIST1 = push_list_1(LIST1, a);

        LIST2->list = LIST1;

        N++;
        if (a == 0) break;
    }
    
    *list1 = LIST1;
    *list2 = LIST2;

    return N;
}

#define UP 0
#define DOWN 1
void output_struct(list_2_t *S) {
    
    printf("\nПроверка значений\n");

    printf("8 -- вверх\n");
    printf("2 -- вниз\n");
    printf("4 -- налево\n");
    printf("6 -- направо\n");
    printf("0 -- выход\n");
    
    int exit = 0, error = 0;
    int status = UP;
    while (1) {
        int a;
        printf("\nВведите направление: ");

        scanf("%d", &a);
    

        if (a == 8) {
            if (status == UP) {
                printf("Элемент не может сместиться  вверх\n");
                error = 1;
            } else {
                status = UP;
            }
                
        } else if (a == 2) {
            if (status == DOWN) {
                printf("Элемент не может сместиться вниз\n");
                error = 1;
            } else {
                status = DOWN;
            }
        } else if (a == 4) {

           
           if (S->prev == NULL) {
                printf("Список еще не начался\n");
                error = 1;
            } else S = S->prev;
 

        } else if (a == 6) {

            
           if (S->next == NULL) {
                printf("Список закончился\n");
                error = 1;
            } else S = S->next;



        } else if (a == 0) {
            exit = 1;
        } else {
            printf("Такого выбора нет\n");
            error = 1;
        }
        
        // print value
        if (exit == 0) {
            if (status == UP && error == 0) {
                printf("Вверхний список не имеет значений\n");
            } else if (status == DOWN && error == 0) {
                // list_1_t *LIST1 = S->list;
                printf("Value: %d\n", S->list->value);
            }
            error = 0;
        } else break;
}


}

void print_struct(list_2_t *S) {

    int cnt = 0;
    while (S != NULL) {
        list_1_t *LIST1 = S->list;

        S = S->next;
        cnt++;
    }

    // printf("S\n-----\n|   |\n-----\n  ⇩\n");
     

    for (int i = 0; i < cnt; i++) {
        printf("-----     ");
    }
    printf("\n");

    for (int i = 0; i < cnt; i++) {
        printf("|   | <-> ");
        if (i == cnt - 1) printf(" NULL");
    }
    printf("\n");
    
    for (int i = 0; i < cnt; i++) {
        printf("-----     ");
    }
    printf("\n");

    for (int i = 0; i < cnt; i++) {
        printf("  ⇩       ");
    }
    printf("\n");



    for (int i = 0; i < cnt; i++) {
        printf("-----     ");
    }
    printf("\n");

    for (int i = 0; i < cnt; i++) {
        printf("|   | ->  ");
        if (i == cnt - 1) printf(" NULL");
    }
    printf("\n");
    
    for (int i = 0; i < cnt; i++) {
        printf("-----     ");
    }
    printf("\n");
}

list_2_t *search_first(list_2_t *LIST2) {
    while (LIST2->prev != NULL) {
        LIST2 = LIST2->prev;
    }
    return LIST2;
}


int main() {
    
    list_2_t *LIST2;
    list_1_t *LIST1;

    printf("Для создания нового элемента в структуре введите его значение\n");
    printf("При введении значения 0 запись остановится\n");
    int N = create_struct(&LIST1, &LIST2);

    printf("Всего кол-ва записанных эл-ов: %d\n", N);
    
    list_2_t *S = search_first(LIST2);

    print_struct(S);
    output_struct(S);

    // очищение памяти
    for (int i = 0; i < N; i++) {
        // возвращает ук-ль на последний вариант
        LIST2 = pop_list_2(LIST2);
        free(LIST1);
        if (LIST2 != NULL) LIST1 = LIST2->list;
    }        

    return 0;
}
