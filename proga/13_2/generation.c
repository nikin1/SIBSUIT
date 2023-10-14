#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Random(int *A, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        A[i] = rand() % 1000;
    }
    for (int i = 0; i < len; i++) {
        printf("%d\n", A[i]);
    }
}

void increase(int *A, int len) {
    for (int i = 0; i < len; i++) {
        A[i] = i;
        printf("%d\n", A[i]);
    }
}

void descending(int *A, int len) {
    for (int i = len; i > 0; i--) {
        A[i] = i;
        printf("%d\n", A[i]);
    }
}

int main() {
    int len = 300;
    int *A;
    A = malloc(len * sizeof(int));
//     Random(A, len);
//     descending(A, len);
    increase(A, len);
    free(A);
    return 0;
}
