#include <stdio.h>
#include <string.h>

int main() {

    char array[] = "DFJSK";
    char result[strlen(array)];
    for (int i = 0; i < strlen(array); i++) {
        result[i] = 90 - (array[i] - 65);
    }
    printf("%s\n", result);


    return 0;
}