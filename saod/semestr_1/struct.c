#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    char *name;
    int age;
    int height;
    struct  stack *next;

};

struct stack *create(struct stack *head, int age, int height, char *name) {        

    struct stack *element; // указатель на новую структуру

    element = (struct stack *)malloc(sizeof(struct stack)); // выделяем память

    element->next = head;
    
    element->age = age;
    element->height = height;
    element->name = name;    
    return element;
}


void all_information(struct stack *p, char *name) {
    int cnt = 0;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) { // strcmp сравнивает строки 
            printf("name: %s\nage: %d\nheight: %d\n", p->name, p->age, p->height);
            cnt = 1;
            break;
        }
        p = p ->next; // продвижение по списку
    }
    if (cnt == 0) {
        printf("element not found\n");
    }
}

struct stack *del_last(struct stack *p) {        

    struct stack *element; // указатель на новую структуру
    element = p->next;
    free(p);
    return element;
}

void del_any(struct stack *p, char *name) {

    
    if (strcmp(p->name, name) == 0) { // проверка на то, что этот элемент является последним в списке
        p = del_last(p);
    }
    else {
        struct stack *element;

        while (p != NULL) {
            
            element = p ->next; // хранит информацию о следующем элементе
            
            if (strcmp(element->name, name) == 0) { //если след елемент тот, который нам подходит
                p->next = element->next; // соединяем наш элемент со следующим после удаленного
                free(element);
                break;
            }
            p = p ->next;            
        }
    }
    

}




int main() {
    int n = 5, size = 6;
    
    char names[][50] = {"Andrey", "Alexander", "Mark", "Nik", "Ivan"};

    struct stack *head;
    
    head = NULL;

    struct stack *first_element_stack;
    

    for (int age = 20, height = 160,i = 0; i < n; age+=10, height+=10,i++) {
        head = create(head, age, height, names[i]);

        if (i == 0) first_element_stack = head; // элемент из начала стека

    }
    
    
    printf("last name: %s\n", head->name); // показываем последний элемент в списке 
    
    all_information(head, "Ivan"); // смотрим все значения этого элемента в стеке 
    
    head = del_last(head); // удаляем последний элемент
    
    printf("last name: %s\n", head->name); // видим, что последний элемент изменился

    

    printf("\n\n\n");
    all_information(head, "Alexander"); // Далее смотрим все значения имени Александр

    del_any(head, "Alexander"); // удаляем элемент с этим именем ( имя может нах-ся в любом месте)

    all_information(head, "Alexander"); // смотрим все значения по этому имени - понимаем, что такого эл-та нет


    free(head);    
    return 0;
}
