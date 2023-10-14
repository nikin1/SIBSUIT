#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct list {
    struct list *next;
    struct list *prev;
    
    int number_bus;
    char name[100];
    int number_route;
} list_t;

list_t *find_last_el(list_t *last_el) {    
    if (last_el != NULL) {
      while (last_el->next != NULL) {
          last_el = last_el->next;
      }
    }
    return last_el;
}

list_t *find_el(list_t *el, int number_bus, int *cnt) {    
    el = find_last_el(el); // если наш элемент не является последним, то мы находим указатель имеенно на последний

    // ищем тот автобус, который нужно удалить
    if (el != NULL) {
        while (1) {
            if (el->number_bus == number_bus) {
                *cnt = 1;
                break;
            } else if (el->prev == NULL) {
                break;
            } else {
                el = el->prev;
            }
        }
    }
    return el;
}


list_t *push(list_t *last_el, int number_bus, char *name, int number_route) {

    last_el = find_last_el(last_el); // если наш элемент не является последним, то мы находим указатель имеенно на последний

    list_t *new;
    new = malloc(sizeof(list_t));
    assert(new != NULL);

    new->number_bus = number_bus;
    new->number_route = number_route;
    strcat(new->name, name);

    if (last_el != NULL) {
    last_el->next = new;
    }
    new->prev = last_el;
    new->next = NULL;
    return new;
}

list_t *pop(list_t *last_el) {
    // элемент может удалятьcя с любого места в списке
    list_t *tmp = NULL; 
    if (last_el != NULL) {

        list_t *prev = last_el->prev;
        list_t *next = last_el->next;


        if (next != NULL && prev != NULL) {
            prev->next = next;
            next->prev = prev;
            tmp = next;
        } else if (prev == NULL && next != NULL) {
            next->prev = NULL;
            tmp = next;
        } else if (prev != NULL && next == NULL) {
            prev->next = NULL;
            tmp = prev;
        }


        free(last_el);
    }

    return tmp;
}

void print_lists(list_t *PARK, list_t *ROUTE) {
    printf("\n");
    if (PARK == NULL) {
        printf("В парке нет автобусов\n");
    } else {
        PARK = find_last_el(PARK);
        printf("Номера автобусов, которые сейчас в парке: ");
        while (PARK != NULL) {
            printf("%d ", PARK->number_bus);
            PARK = PARK->prev;
        }
        printf("\n");
    }
    
    if (ROUTE == NULL) {
        printf("Автобусов, которые выполняют маршрут, нет\n");
    } else {
        ROUTE = find_last_el(ROUTE);
        printf("Номера автобусов, которые сейчас на маршруте: ");
        while (ROUTE != NULL) {
            printf("%d ", ROUTE->number_bus);
            ROUTE = ROUTE->prev;
        }
        printf("\n");
   
    }
}


int main() {

    list_t *PARK = NULL, *ROUTE = NULL;
    while (1) {
        int a;
        printf("\nВыберите один из предложенных вариантов:\n1.Добавить новый автобус в парк\n");
        printf("2.Выезд автобуса из парка по указанному маршруту\n");
        printf("3.Въезд автобуса обратно в парк\n");
        printf("4.Посмотреть информацию\n");
        printf("5.Выход из программы\n");
        
        printf(": "); scanf("%d", &a);
        int exit = 0;

        int number_bus, number_route;
        char name[100];
        if (a == 1) {
            printf("Введите номер автобуса: "); scanf("%d", &number_bus);
            printf("Введите номер маршрута: "); scanf("%d", &number_route);
            printf("Введите фамилию и инициалы водителя: "); scanf("%s", name);
            
            PARK = push(PARK, number_bus, name, number_route);
        } else if (a == 2) {
            printf("Введите номер автобуса: "); scanf("%d", &number_bus);

            int cnt = 0;
            PARK = find_el(PARK, number_bus, &cnt);
            if (cnt == 1) {
                ROUTE = push(ROUTE, PARK->number_bus, PARK->name, PARK->number_route);
                PARK = pop(PARK);
            } else {
                printf("Найти такой автобус не удалось\n");
            }
        }
        else if (a == 3) {
            int cnt = 0;
            printf("Введите номер автобуса: "); scanf("%d", &number_bus);            
            ROUTE = find_el(ROUTE, number_bus, &cnt);
            if (cnt == 1) {
                PARK = push(PARK, ROUTE->number_bus, ROUTE->name, ROUTE->number_route);
                ROUTE = pop(ROUTE);
            } else {
                printf("Найти такой автобус не удалось\n");
            }
        }
        
        else if (a == 4) {
            print_lists(PARK, ROUTE);
        }
        else if (a == 5) {
            exit = 1;
        } 
        else {
            printf("такого выбора нет\n");
        }

        if (exit == 1) break;
    }

    ROUTE = find_last_el(ROUTE);
    while (ROUTE != NULL) {
        ROUTE = pop(ROUTE);
    }

    PARK = find_last_el(PARK);
    
    while (PARK != NULL) {
        PARK = pop(PARK);
    }
    


    return 0;
}


