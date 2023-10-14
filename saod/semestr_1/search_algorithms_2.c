#include "search.h"

typedef struct trees {
    // Деревья представлены с помощью списков смежности
    
    int value;
    int key;


    int route_list[100];
} trees_t;

trees_t *search(trees_t Array[], int cnt_nods, int key) {
    // поиск будет сделан через обход в ширину

    trees_t *A;
    // memory_malloc(A, cnt_nods);
    A = malloc(cnt_nods * sizeof(trees_t));

    queue_t *Q = NULL;
    Q = push_back(Q, 0); // 0 - самый первый узел

    int index = 0, max_index = 1;

    while (Q != NULL) {

        int node = Q->value;
        // если это тот узел, то удаляем
        if (Array[node].key == key) {
            printf("KEY1\n");
        } else {
            A[index].value = Array[node].value;
            A[index].key = Array[node].key;



            int tmp_index = 0;
            for (int j = 0; Array[node].route_list[j]; j++) {
                
                int route = Array[node].route_list[j];
                
    
                if (Array[route].key != key) {
                    Q = push_back(Q, route);
                    A[index].route_list[tmp_index++] = max_index;
                    
                    // printf("A[%d].route_list[%d] = %d\n", index, tmp_index - 1, max_index);
                    
                    max_index++;
                    // printf("max_index_prev: %d\n", A[index].route_list[tmp_index - 1]);
                }
            }
            
            index++;
        }
        Q = pop_front(Q);
    }
    
    return A;
}

int main() {
    trees_t *A;
    int size = 10;

    // memory_malloc(A, size);

    A = malloc(size * sizeof(trees_t));

    A[0].key = 0;
    A[1].key = 0;
    A[2].key = 0;
    A[3].key = 0;
    A[4].key = 0;
    A[5].key = 0;
    A[6].key = 0;
    A[7].key = 0;
    A[8].key = 0;
    A[9].key = 0;

    A[0].route_list[0] = 1;
    A[0].route_list[1] = 2;
    A[0].route_list[2] = 3;


    A[1].route_list[0] = 4;
    A[1].route_list[1] = 5;

    A[2].route_list[0] = 6;
    A[2].route_list[1] = 7;

    A[3].route_list[0] = 8;
    A[3].route_list[1] = 9;

    // Во время поиска все элементы будут копироваться в другой массив, память на 
    // старый очиститься, с помощью этого удобнее осуществлять удаление эл-ов
    
    // trees_t *B = search(A, size, 1);
    // проверка на то, что В скопировалась без изменений => нужного ключ не найден
    // assert(B[0].route_list[0] == 1);
    // assert(B[0].route_list[1] == 2);
    // assert(B[0].route_list[2] == 3);

    // assert(B[3].route_list[0] == 8);
    // assert(B[3].route_list[1] == 9);
    // free(B);
    

    trees_t *C = NULL;
    A[9].key = 1; // 9 !!!
    C = search(A, size, 1);
    
    assert(C[0].route_list[0] == 1);
    assert(C[0].route_list[1] == 2);
    assert(C[0].route_list[2] == 3);

    assert(C[3].route_list[0] == 8);
    assert(C[3].route_list[1] != 9); // != 9
    
    // printf("-- %d -- \n", C[3].route_list[1]);
    free(A);
    free(C);
    
    return 0;
}

