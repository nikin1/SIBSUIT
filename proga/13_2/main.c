#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int sort_simple_choice(int mass[],int N, int *cnt_C, int *cnt_M);
void bubble( int size, int *a, int *cnt_C, int *cnt_M);
void heapSort(int *numbers, int array_size, int *cnt_C, int *cnt_M);

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

int read_file(int *A, int len, int mod) {
    int res = 0;
    char file[256];
    memset(file, '\0', 255);
    if (mod == 0) {
        printf("Введите название файла: ");
        scanf("%s", file);
    } else if (mod == 1) {
        strcat(file, "descending5.txt");
    } else if (mod == 2) {
        strcat(file, "random5.txt");
    } else if (mod == 3) {
        strcat(file, "increase5.txt");
    }

    // printf("file: %s\n", file);
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Открыть файл не удалось\n");
        res = 1;
    } else {
        char str[100], *estr;
        int i = 0;
        while (i < len) {
            estr = fgets(str, sizeof(str), fp); // Чтение построчно из файла
            if (feof(fp)) {
                break;
            } else {
                A[i] = atoi(str); // Перевод строки в число
            }
            i++;
        }
    }
    return res;
}

void test(void) {
//     printf("<<>>\n");
    int len;
    int *A, *B, *C;
    A = malloc(1024 * sizeof(int));
    B = malloc(1024 * sizeof(int));
    C = malloc(1024 * sizeof(int));
    printf("%4s |            %s           |        %s        |           %s         |\n", "LEN", "BUBBLE", "SIMPLE_CHOISE", "HeapSort");
    printf("     |");
    printf("  УБЫВ.  |  СЛУЧ.  |  ВОЗР.  |");printf("  УБЫВ.  |  СЛУЧ.  |  ВОЗР.  |");printf("  УБЫВ.  |  СЛУЧ.  |  ВОЗР. |\n");

    for (len = 100; len < 600; len += 100) {
        int CNT[10];
        for (int i = 1; i < 4; i++) {
            int cnt_C = 0, cnt_M = 0;
            read_file(A, len, i);
            read_file(B, len, i);
            read_file(C, len, i);
            
            bubble(len, A, &cnt_C, &cnt_M);
            CNT[i] = cnt_C + cnt_M; // CNT[1], CNT[2], CNT[3]
            // printf("Bubble: %d\n", cnt_C + cnt_M);
            
            cnt_C = 0;
            cnt_M = 0;
            sort_simple_choice(B, len, &cnt_C, &cnt_M);
            CNT[i + 3] = cnt_C + cnt_M; // CNT[4], CNT[5], CNT[6]
  
            heapSort(A, len, &cnt_C, &cnt_M);
            CNT[i + 6] = cnt_C + cnt_M; // CNT[7], CNT[8], CNT[9]

          // printf("Simple choice: %d\n", cnt_C + cnt_M);
        }
        printf("%4d | %7d | %7d | %7d | %7d | %7d | %7d | %7d | %7d | %7d|\n", len, CNT[1], CNT[2], CNT[3], CNT[4], CNT[5], CNT[6], CNT[7], CNT[8], CNT[9]);

    }
    free(B);
    free(A);
}

int main() {
    
    int choise;
    printf("Виды сортировки:\n");
    printf("1 - Метод пузырьковой сортирoвки\n2 - Метод пирамидной сортировки\n3 - Метод простого выбора\n4 - Тестирование всех сортирвок\n");
    printf("Выберите способ сортировки: ");
    scanf("%d", &choise);
 
    if (choise != 1 && choise != 2 && choise != 3 && choise != 4) {
        printf("Такого выбора нет\n");
    } else {
        if (choise == 4) {
            test();
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
                        int res3 = 0;
                        switch(choise_2) {
                            case 1:
                                printf("Задайте массив: ");
                                input(A, len);
                                break;
                            case 2: 
                                generation(A, len);
                                break;
                            case 3:
                                res3 = read_file(A, len, 0);
                                break;
                                
                        }
                        if (res3 == 0) {
                            printf("ВАШ МАССИВ: \n");
                            print(A, len);
                            
                            int cnt_C = 0, cnt_M = 0;
                            switch(choise) {
                                case 1:
                                    bubble(len, A, &cnt_C, &cnt_M); 
                                    break;
                                case 2: 
                                    heapSort(A, len, &cnt_C, &cnt_M);
                                    break;
                                case 3:
                                    sort_simple_choice(A, len, &cnt_C, &cnt_M);
                                    break;
                            }
                            
                            
                            printf("ВАШ ОТСОРТИОВАННЫЙ МАССИВ: \n");
                            print(A, len);
                            printf("Кол-во сравнений: %d\n", cnt_C);
                            printf("Кол-во перессылок: %d\n", cnt_M);
                        }
                        free(A);
                    }
            }
        }
    } 
    
    return 0;
}

