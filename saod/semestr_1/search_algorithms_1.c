#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Tkeyvalue {
    int value;
    int key;
} Tkeyvalue_t;

void print_Tkeyvalue(Tkeyvalue_t Array[], int n) {
    printf("value:[key]: ");
    for (int i = 0; i < n; i++) {
        printf("%d:[%d] ", Array[i].value, Array[i].key);
    }
    printf("\n");
}

void print_cnt_value(int cnt, int cnt_array[]) {
    printf("Кол-во совпадений: %d\n", cnt);

    if (cnt > 0) {
        printf("Номера совпадений: ");
        for (int i = 0; i < cnt; i++) {
            printf("%d", cnt_array[i]);
            if (i != cnt - 1) printf(", ");
        }
        printf("\n");
    }
    
}

void InsertionSort(Tkeyvalue_t Array[], int n) {
    int location;
    Tkeyvalue_t new_element;
 
    for (int i = 1; i < n; i++)
    {
        new_element = Array[i];
        location = i - 1;
        while(location >= 0 && Array[location].key > new_element.key) {
            Array[location+1] = Array[location];
            location = location - 1;
        }
        Array[location+1] = new_element;
    }
}


void intput_size_key(int *size, int *key) {
    
    printf("Enter size: ");
    scanf("%d", size);

    printf("Enter key: ");
    scanf("%d", key);
}

Tkeyvalue_t *generate_random_array(int size) {
    Tkeyvalue_t *A;
    srand(time(NULL));
    A = malloc(size * sizeof(Tkeyvalue_t));

    for (int i = 0; i < size; i++) {
        A[i].key = random() % size;
    }

    for (int i = 0; i < size; i++) {
        A[i].value = random() % size;
    }


    return A;
}

void linear_search(Tkeyvalue_t A[], int size, int key, int *cnt, int cnt_index_array[]) {
    int index = 0;
    *cnt = 0;
    for (int i = 0; i < size; i++) {
        if (A[i].key == key) {
            *cnt = *cnt + 1;
            cnt_index_array[index++] = A[i].value;
        }
    }
}

void binary_search(Tkeyvalue_t Array[], int size, int key, int *cnt, int cnt_index_array[]) {
    int left = 0, right = size - 1;
    int index = 0;
    int middle;
    *cnt = 0;
    while (left <= right) {
        middle = (left + right) / 2;
        
        if (key == Array[middle].key) {
            *cnt = *cnt + 1;
            cnt_index_array[index++] = Array[middle].value;
            break;

        } else if (Array[middle].key < key) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    // проверка на то, что еще существуют нужные эл-ты правее или левее середины
    for (int j = 1; (middle + j) < size  && key == Array[middle + j].key; j++) {
            *cnt = *cnt + 1;
            cnt_index_array[index++] = Array[middle + j].value;
    }

    for (int j = 1; (middle - j) <= 0  && key == Array[middle - j].key; j++) {
            *cnt = *cnt + 1;
            cnt_index_array[index++] = Array[middle - j].value;
    }
}


int main() {
    int size, key;
    
    intput_size_key(&size, &key);
    if (size > 0) {
        int cnt, *cnt_array_1, *cnt_array_2;
        cnt_array_1 = malloc(size * sizeof(int));
        cnt_array_2 = malloc(size * sizeof(int));

        Tkeyvalue_t *Array = generate_random_array(size);
        
        print_Tkeyvalue(Array, size);

        printf("\nЛинейный поиск: \n");
        linear_search(Array, size, key, &cnt, cnt_array_1);
        print_cnt_value(cnt, cnt_array_1);




        InsertionSort(Array, size);

        printf("\nОтсортированный массив: \n");
        print_Tkeyvalue(Array, size);
        
        printf("\nБинарный поиск\n");
        binary_search(Array, size, key, &cnt, cnt_array_2);
        print_cnt_value(cnt, cnt_array_2);


        free(cnt_array_1);
        free(cnt_array_2);
        free(Array);
    }




    return 0;
}

