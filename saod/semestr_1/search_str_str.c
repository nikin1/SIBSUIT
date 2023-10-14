#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define NO_OF_CHARS 256

// задание №3
int naive_search(char *s, int N, char *q, int M) {
    
    int res = -1;
    
    for (int k = 0; k < N; k++)  {

        if (s[k] == q[0]) {
            res = k;
            int j = 0;
            // поиск подстроки 
            for (int k_2 = k; k_2 < k + M && k_2 < N; k_2++) {
                if (s[k_2] != q[j++]) {
                    res = -1;
                    break;
                }
            }

            if (res != -1 && j == M) break;
        }
    }

    return res;
}

// задание №4

int search_KMP (char *s, char *p) {
	int i, j, N, M;
	N = strlen(s);
	M = strlen(p);

    // Динамический массив длины М
	int *d = (int*)malloc(M * sizeof(int));

	// Вычисление префикс-функции
	d[0] = 0;
	for(i = 1, j = 0; i < M; i++)
	{
		while(j > 0 && p[j] != p[i])
			j = d[j-1];
		if(p[j] == p[i])
			j++;
		d[i] = j;
	}

	// Поиск
	for(i = 0, j = 0; i < N; i++)
	{
		while(j > 0 && p[j] != s[i])
			j = d[j - 1];
		if(p[j] == s[i])
            j++;
		if(j == M)
        {
		    free(d);
            return i - j + 1;
        }
	}
    free(d);
	return -1;
}

// №5 
 




int max(int a, int b) {
    return (a > b) ? a : b;

}


// Функция предварительной обработки для эвристики плохого характера Бойера Мура

void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS]) {
    int i;

    // Инициализируем всё как -1
    for (i = 0; i < NO_OF_CHARS; i++)

        badchar[i] = -1;
    // Заполнняем фактическое значение последнего появления символа

    for (i = 0; i < size; i++)

        badchar[(int) str[i]] = i;

}

 

int search_BM(char *txt, char *pat) {
    int m = strlen(pat);

    int n = strlen(txt);
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);
    
    int s = 0; // s сдвиг шаблона по отношению к тексту

    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            // printf("\n pattern occurs at shift = %d", s);
            return s;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);

    }
    return s;

}




int main() {
    int res;
    
    res = naive_search("abcabc", 6, "abc", 3);
    assert(res == 0);

    res = naive_search("abcbbb", 6, "bbb", 3);
    assert(res == 3);

    res = naive_search("abcbbb", 6, "ccc", 3);
    assert(res == -1);

    res = search_BM("abcccbbb", "ccc");
    assert(res == 2);
    // printf("res: %d\n", res);

    res = search_BM("abcccbbb", "bb");
    assert(res == 5);
    // printf("res: %d\n", res);

    res = search_BM("abcccbbb", "bb");
    assert(res == 5);
    
    res = search_KMP("abcccbbb", "bb");
    assert(res == 5);

    res = search_KMP("cccbbb", "a");
    assert(res == -1);
    
    return 0;
}

