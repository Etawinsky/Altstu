/* Задан список чисел. Образовать из него новый, исключив из исходного
 минимальное число элементов так, чтобы список стал неубывающим */

#include <stdio.h>
#include "list.h"
#define LINELENGTH 1024
int main()
{

	FILE *fp;
    char line[LINELENGTH];
    char *p;
	int c, n;
	struct List *test = NULL;
	struct List *answer = NULL;
	struct List *tst = NULL;
	test = list_init();
    printf("введите имя файла:");
    scanf("%s", line);
    if((fp = fopen(line,"r")) == NULL){
        fprintf(stderr, "Нет такого файла\n");
        return 1;
    }
    /* читаем строку за строкой */
	p = line;
    while(fgets (line, LINELENGTH, fp)){
         while(sscanf(p, "  %d%n", &c, &n) == 1 ){
			list_append(test, c);
             p +=n;
        }
    }
	tst = list_init();
	list_append(tst, 2);
	list_append(tst, 5);
	answer = list_insert(test,tst,4);
	/*	while(answer->head != NULL){
		printf("%d\n", answer->head->number);
		answer->head = answer->head->next;
	}*/
	
//	answer = list_LIS(test);
	fclose(fp);
/*
	while ((c = getchar())!= '\n' && c != EOF);
	printf("Сохранить в файл? [y/n]:");
	scanf("%c", &c);
	switch (c){
    	case 'y': case 'Y': 
    	printf("Записано в \"output.txt\"\n");
    	fp = fopen("output.txt", "a");
    	fprintf(fp, "------------------------\n");
		while(answer->head != NULL){
			fprintf(fp, "%d ", answer->head->number);
			answer->head = answer->head->next;
		}
    	fprintf(fp,"\n");
    	fclose(fp);
    	break;
	}
*/
	return 0;
}
