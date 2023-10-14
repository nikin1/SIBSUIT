
int sort_simple_choice(int mass[], int N, int *cnt_C, int *cnt_M)
{

for (int i = 0; i < N; i++)
{
    int minPosition = i, tmp;
    for (int j = i + 1; j < N; j++) {
        if (mass[minPosition] > mass[j]) {
            *cnt_C = *cnt_C + 1;
            minPosition = j;
            *cnt_M = *cnt_M + 1;
        }
    }

    tmp = mass[minPosition];
    mass[minPosition] = mass[i];
    mass[i] = tmp;
    *cnt_M = *cnt_M + 3;
}
    return *mass; 
}
