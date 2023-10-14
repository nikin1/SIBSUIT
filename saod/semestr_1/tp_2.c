#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_matrix(int row, int column) {
	int **A;
	A = malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++) {
		A[i] = malloc(column * sizeof(int));
	}
	// A[0][0] = 1;
	// printf("<<>>\n");
	return A;
}

void remove_matrix(int**A, int row) {
	for (int i = 0; i < row; i++) {
		free(A[i]);
	}
	free(A);
}

void random_matrix(int **A, int row, int col) {
	srand(time(NULL));
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			A[x][y] = rand() % 1000;
		}
	}
}

void input_matrix(int **A, int row, int col) {
	printf("Заполните матрицу %d * %d\n", row, col);
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			scanf("%d", &A[x][y]);
		}
	}
}

int choice_create_matrix(int *x, int *y) {
	printf("Выберите способ задать матрицу\n1.Ввод с клавиатуры\n2.Заполнение случайными числами\n: ");
	int c;
	scanf("%d", &c);
	printf("Задайте размер матрицы\n");
	printf("x: ");
	scanf("%d", x);
	printf("y: ");
	scanf("%d", y);
	return c;
}

int search_max_value(int **A, int row, int col, int *max_x, int *max_y) {
	int maxi = -100000, cnt = 0;
	//*max_x = 0;
	//*max_y = 0;

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (A[x][y] > maxi) {
				maxi = A[x][y];
				*max_x = x;
				*max_y = y;
				cnt++;
			}
		}
	}
	return cnt;
}

int **create_matrix_b(int **A, int row, int col, int max_x, int max_y) {
	int **B, index_x = 0, index_y = 0;
	B = create_matrix(row - 1, col - 1);

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (x != max_x && y != max_y) {
				B[index_x++][index_y++] = A[x][y];
			}
		}
	}
	return B;
}

int cnt_row_zeros(int **A, int row, int col) {
	int cnt = 0;

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (A[x][y] == 0) {
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

void reserve_diagonal(int **A, int row, int col) {
	int list_diag[row], index = 0;

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (x == y) {
				list_diag[index++] = A[x][y];
			}
		}
	}
	index--;
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (x == y) {
				A[x][y] = list_diag[index--];
			}
		}
	}
}

void print_matrix(int **A, int row, int col) {
	printf("\n");
	for (int x = 0; x < row; x++) {
		printf("\n");
		for (int y = 0; y < col; y++) {
			printf("%d ", A[x][y]);
		}
	}
}

int main() {
	int **A, x, y;
	int choice = choice_create_matrix(&y, &x);
	// printf("x: %d   ---   y: %d\n", x, y);
	if (choice == 1 || choice == 2) A = create_matrix(y, x);
	// printf("<<>>\n");
	// A[0][0] = 2;
	// if (choice == 1) input_matrix(A, x, y);
	// else if (choice == 2) random_matrix(A, x, y);
	// else printf("Такого выбора нет");

	// printf("Ваша матрица/n");
	// print_matrix(A, x, y);

	// int max_x, max_y;
	// int tmp = search_max_value(A, x, y, &max_x, &max_y);
	// if (tmp != 0) {
	// 	int **B = create_matrix_b(A, x, y, max_x, max_y);
	// 	printf("Вывод матрицы В\n");
	// 	print_matrix(B, x - 1, y - 1);

	// } else {
	// 	printf("Максимального элемента в матрице нет");
	// }


	// int cnt_zero = cnt_row_zeros(A, x, y);
	// printf("Кол-во строк в которых есть нули в матрице А: %d", cnt_zero);

	// printf("Нахождение обратной диагонали матрицы\n");
	// reserve_diagonal(A, x, y);
	// print_matrix(A, x, y);

	// remove_matrix(A, x);
	// for (int i = 0; i < y; i++) {
	// 	free(A[i]);
	// }
	// free(A);
	return 0;
}