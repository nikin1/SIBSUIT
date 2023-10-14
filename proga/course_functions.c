#include <stdio.h>


int search_dates(char *file_name, int *max_year) {
    int cnt = 0, max_cnt_year = 0;
    int days;
    FILE *fp;
    fp = fopen(file_name, "w");

    for (int year = 1901; year <= 2000; year++) {
        int year_tmp = year % 100;
        int cnt_year = 0;

        for (int month = 1; month <= 12; month++) {
            if (month == 1 || month == 3 || month == 5 || month == 7
            || month == 8 || month == 10 || month == 12) {
                days = 31;
            } else if (month == 2) {
                if (month % 4 == 0) days = 29;
                else days = 28;
            } else {
                days = 30;
            }
            for (int day = 1; day < days; day++) {
                if (day * month == year_tmp) {
                    cnt++;
                    cnt_year++;

                    fprintf(fp, "%02d.%02d.%d\n", day, month, year);
                }
            }
        }

        // поиск года с макисмальным количеством таких дат
        if (cnt_year > max_cnt_year) {
            max_cnt_year = cnt_year;
            *max_year = year;
        }

    }
    fclose(fp);
    return cnt;
}

int check_date(int day, int month, int year) {
    if (day * month == (year % 100)) return 0;
    else return 1; 
}