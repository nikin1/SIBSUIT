#include <stdio.h>


int search_dates(char *file_name, int *max_year);
int check_date(int day, int month, int year);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Введите 1 аргумент для создания файла\n");
    } else {
        int max;
        int cnt = search_dates(argv[1], &max);
        printf("Количество дат: %d\n", cnt);
        printf("Год, в к-ом число таких дат максимально: %d\n", max);   

        int day = 1, month = 5, year = 1905;
        printf("\nПроверка числа %02d.%02d.%d\n", day, month, year);

        if (check_date(day, month, year) == 0) printf("Данное число подходит\n");
        else printf("Данное число не подходит\n");



        day = 1, month = 5, year = 1906;
        printf("\nПроверка числа %02d.%02d.%d\n", day, month, year);

        if (check_date(day, month, year) == 0) printf("Данное число подходит\n");
        else printf("Данное число не подходит\n");

    }

    return 0;
}

