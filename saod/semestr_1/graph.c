#include "graph.h"

#define STATUS_0 0 // необнаруженная вершина
#define STATUS_1 1 // обнаруженная, но не посещенная вершина
#define STATUS_2 2 // обработанная вершина


// графы представлены в матричном виде, где 0 - значит, что м/у узлами нет свзи, а 1 - наоборот
// Поиск деревьев осуществлялся через глубину

//  данная функция ищет свясь м/у узлами
int route_search(int **mas, int cnt_nodes, int node_1, int node_2) {
    int route = 0;
    Stack_t *S = NULL;

    int nodes[cnt_nodes]; // вершины графа
    for (int i = 0; i < cnt_nodes; i++) {
        nodes[i] = STATUS_0; // исходно все вершины равны 0
    }

    // Stack.push(0);
    S = Push(S, node_1); //  !!!!!! помещаем в очередь первую вершину --  От нее начинается поиск

    while (S != NULL) { // пока стек не пуст
        int node = S->value; // извлекаем вершину
        S = Pop(S);
        if (nodes[node] == STATUS_2) continue;
        nodes[node] = STATUS_2; // отмечаем ее как посещенную

        for (int j = cnt_nodes - 1; j >= 0; j--) { // проверяем для нее все смежные вершины
            if (mas[node][j] == 1 && nodes[j] != STATUS_2) { // если вершина смежная и не обнаружена
                // значит есть маршрут
                if (node == node_2 || j == node_2) route = 1; // Если в маршруте один из узлов явлвяется вторым узлом, то значит маршрут построен
                
                S = Push(S, j); // добавляем ее в cтек
                nodes[j] = STATUS_1; // отмечаем вершину как обнаруженную
            }
        }
        if (route == 1) break; // если маршрут найден, то оставливаемся 
    }
    return route;
}



int main() {
    int cnt_nodes = 4;
    
    int **mas;
    mas = malloc(cnt_nodes * sizeof(int *));

    for (int i = 0; i < cnt_nodes; i++) {
        mas[i] = malloc(cnt_nodes * sizeof(int));
    }

    /*
     0 --> 1
     |     |
     ^     ^ 
     3 ->  2
    */
    
    mas[0][0] = 0;
    mas[0][1] = 1;
    mas[0][2] = 0;
    mas[0][3] = 0;

    mas[1][0] = 0;
    mas[1][1] = 0;
    mas[1][2] = 1;
    mas[1][3] = 0;

    mas[2][0] = 0;
    mas[2][1] = 0;
    mas[2][2] = 0;
    mas[2][3] = 1;
    
    mas[3][0] = 1;
    mas[3][1] = 0;
    mas[3][2] = 0;
    mas[3][3] = 0;
    
    int node_1, node_2, res;
    
    node_1 = 0, node_2 = 3;
    res = route_search(mas, cnt_nodes, node_1, node_2);
    
    assert(res == 1);

    node_1 = 0, node_2 = 1;
    res = route_search(mas, cnt_nodes, node_1, node_2);
    assert(res == 1);
    
    mas[0][0] = 0;
    mas[0][1] = 1;
    mas[0][2] = 0;
    mas[0][3] = 1;

    mas[1][0] = 0;
    mas[1][1] = 0;
    mas[1][2] = 1;
    mas[1][3] = 0;

    mas[2][0] = 0;
    mas[2][1] = 0;
    mas[2][2] = 0;
    mas[2][3] = 1;
    
    mas[3][0] = 0;
    mas[3][1] = 0;
    mas[3][2] = 0;
    mas[3][3] = 0;


    node_1 = 0, node_2 = 1;
    res = route_search(mas, cnt_nodes, node_1, node_2);
    assert(res == 1);


    node_1 = 0, node_2 = 3;
    res = route_search(mas, cnt_nodes, node_1, node_2);
    assert(res == 1);


    node_1 = 3, node_2 = 0;
    res = route_search(mas, cnt_nodes, node_1, node_2);
    assert(res == 0);

    // if (res == 0) printf("Маршрут междом узлом %d и узлом %d не сущеcтвует\n", node_1, node_2);
    // else if (res == 1) printf("Маршрут междом узлом %d и узлом %d сущеcтвует\n", node_1, node_2);


    for (int i = 0; i < cnt_nodes; i++) {
        free(mas[i]);
    }
    return 0;
}

