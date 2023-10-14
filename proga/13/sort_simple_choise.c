int sort_simple_choice(int mass[],int N)
{
for (int i = 0; i < N; i++)
{
    int minPosition = i, tmp;
    for (int j = i + 1; j < N; j++)
        if (mass[minPosition] > mass[j])
            minPosition = j;
    tmp = mass[minPosition];
    mass[minPosition] = mass[i];
    mass[i] = tmp;
}
    return *mass; 
}

