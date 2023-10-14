#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>

//у меня 22 вариант
//gcc cursovic.c -o translate && ./translate Text_rus.txt Dictionary.txt Text_eng.txt

typedef struct dictionary{
    char ru[20];
    char en[20];
    struct dictionary *next;
} dictionary_t;

dictionary_t *head;

int main(int argc, char **argv){

    if(argc != 4){
        printf("ERROR\n");
        return 0;}
    char *t_rus = argv[1];
    char *diction = argv[2];
    char *t_eng = argv[3];

    setlocale(LC_ALL,"Russian");

    //создание списка из dictionary.txt
    FILE *ptr;
    char ch[2];
    dictionary_t *cur; dictionary_t *t;
    cur = (dictionary_t*)malloc(sizeof(dictionary_t));
    head = cur;
    if ((ptr=fopen(diction,"r"))!=NULL){//создание списка переводчика
        while (!feof(ptr)){
            fscanf(ptr,"%s%s%s",cur->ru,ch,cur->en);
            // printf("%s - %s \n",cur->ru,cur->en);
            t=cur;
            cur = (dictionary_t*)malloc(sizeof(dictionary_t));
            cur->next = NULL;
            t->next = cur;
        }
        fclose(ptr);
        //t->next = NULL;
    }
    //....................................................................


    FILE *f;
    f = fopen(t_eng, "w");


    
    if ((ptr=fopen(t_rus,"r"))!=NULL){//создание списка переводчика
        while (!feof(ptr)){

            char tmp[256];
            // считываем всю строку (от начала до \n)
            fgets(tmp, 256, ptr);

            dictionary_t *dict = head;

            char *p;
            
            while (dict != NULL) {
                // проверяем есть ли в этой строчке нужное нам слово
                p = strstr(tmp, dict->ru);

                // если нашли подстроку
                if (p != NULL) {
                    break;
                }

                dict = dict->next;
            }

            /*
                Далее проходимся посимвольно по этой строке
                Если адрес сивола в строке &tmp[i] == p  равен указателю 
                То нам нужно в строке tmp не записать это слово на русском(поэтому i +=)
                А нужно записать это слово на английском
            */
            int i = 0;
            while (tmp[i]) {
                if  (  &tmp[i] == p  && p != NULL  ) {
                    // printf("%s\n", p);
                    fprintf(f, "%s", dict->en);
                    
                    i += strlen(dict->ru);
                    i -= 1;
                } else {
                    fprintf(f, "%c", tmp[i]);
                }

                i++;
            }
        }


        fclose(ptr);
        fclose(f);



    }

    return 0;
}