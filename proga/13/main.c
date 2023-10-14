#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sort_simple_choice(int mass[],int N);
void bubble( int size, int *a);

void print(int *A, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}


void input(int *A, int len) {
    for (int i = 0; i < len; i++) {
        scanf("%d", &A[i]);
    }
}

void generation(int *A, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        A[i] = rand() % 1000;
    }
}

void read_file(int *A, int len) {
    FILE *fp;
    fp = fopen("array.txt", "r");
    
    if (fp == NULL) {
        printf("Открыть файл не удалось\n");
    } else {
        char str[100], *estr;
        int i = 0;
        while (i < len) {
            estr = fgets(str, sizeof(str), fp); // Чтение построчно из файла
            if (feof(fp)) {
                break;
            } else {
//                 printf("str: %s\n", str);
                A[i] = atoi(str); // Перевод строки в число
            }
            i++;
        }
    }
        
}


int main() {
    
    int choise;
    printf("Виды сортировки:\n");
    printf("1 - Метод пузырьковой сортирвки\n2 - Метод пирамидной сортировки\n3 - Метод простого выбора\n");
    printf("Выберите способ сортировки: ");
    scanf("%d", &choise);
    
    if (choise != 1 && choise != 2 && choise != 3) {
        printf("Такого выбора нет\n");
    } else {    
        int choise_2;
        printf("Способы заполнение массива:\n");
        printf("1 - Ввод с клавиатуры\n2 - Датчик случайных чисел\n3 - Чтение из файла\n");
        printf("Выберите способ задать массив: ");
        scanf("%d", &choise_2);
        
        if (choise_2 != 1 && choise_2 != 2 && choise_2 != 3) {
            printf("Такого выбора нет\n");
        } else {
            int len;
            printf("Задайте длину массива: ");
            scanf("%d", &len);
            if (len <= 0) {
                printf("Длина массив не может быть отрицательной\n");
            } else {
                int *A;
                A = malloc(len * sizeof(int));
                switch(choise_2) {
                    case 1:
                        printf("Задайте массив: ");
                        input(A, len);
                        break;
                    case 2: 
                        generation(A, len);
                        break;
                    case 3:
                        read_file(A, len);
                        break;
                        
                }
                
                printf("ВАШ МАССИВ: \n");
                print(A, len);
                
                
                switch(choise) {
                    case 1:
                        bubble(len, A); 
                        break;
                    case 2: 
                        printf("Тут надо добавить пирамидную сортировку\n");
                        break;
                    case 3:
                        sort_simple_choice(A, len);
                        break;
                }
                
                
                printf("ВАШ ОТСОРТИОВАННЫЙ МАССИВ: \n");
                print(A, len);
                
                
                
                free(A);
            } 
        }
    } 
    
    return 0;
}

