#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// 1 Вопрос
/*
По кол-ву сравнений и каличеству требуемой памяти:
1. Быстрая сортировка
2. Сортировка вставками
3. Сортировка пузыком 
4. Сортировка выбором
5. Сортировка слиянием

По кол-ву сравнений:
1. Сортировка вставками
2. Сортировка выбором
3. Сортировка слиянием
4. Сортировка пузыком 
5. Быстрая сортировка

*/

// 4 вопрос
/*
По производительности на 1000 элементов очередность будет следующая:
1. Сортировка выбором
2. Сортировка вставками
3. Сортировка пузыком
4. Сортировка слиянием
5. Быстрая сортировка
Однако, если тестировать на меньшее кол-во элеметов, то р-ты могут отличаться

*/

// 5 вопрос
/*
По-моему мнению лучше всего подойдет сортировка вставками, т.к. из второго элемента
поочередно будут переходить элементы в уже отсортированный первый массив
*/

void InsertionSort(char *array, int n) {
    int tmp, location;
 
    for (int i = 1; i < n; i++)
    {
        tmp = array[i];
        location = i - 1;
        while(location >= 0 && array[location] > tmp) {
            array[location+1] = array[location];
            location = location - 1;
        }
        array[location+1] = tmp;
    }
}


int main() {
    // тестирование сортировки
    int size = 256;
    char *str;
    str = malloc(size * sizeof(char));
    
    memset(str, '\0', size);

    strcat(str, "acdb");

    InsertionSort(str, 4);
    assert(strcmp(str, "abcd") == 0);


    memset(str, '\0', 5);
    strcat(str, "15423");

    InsertionSort(str, 5);
    assert(strcmp(str, "12345") == 0);
    


    free(str);
    return 0;
}
