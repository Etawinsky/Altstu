/* 	Дополнить упорядоченный односвязный циклический список 
 	новой информацией так, чтобы список остался упорядоченным и 
 	сделать этот список списком с головой */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define LINELENGTH 1024
int main()
{

	FILE *fp;
    char line[LINELENGTH];
    char *p;
	int c, n;
	int *array = NULL;
	int arraysize = 0;
	struct List *test = NULL;
	struct List *answer = NULL;
	struct Node *tmp = NULL;
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
			list_insert(test, c);
             p +=n;
        }
    }
	fclose(fp);
	
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
			array = realloc(array, (arraysize + 1)* sizeof(int));
			array[arraysize++] = c;
             p +=n;
        }
    }
	//printf("%d\n", test->tail->number);
	answer = instosrt(test, array, arraysize);

	tmp = answer->head;
	while ((c = getchar())!= '\n' && c != EOF);/* отсеять всякий мусор */
	printf("Сохранить в файл? [y/n]:");
	scanf("%c", &c);
	switch (c){
    	case 'y': case 'Y': 
    	printf("Записано в \"output.txt\"\n");
    	fp = fopen("output.txt", "a");
    	fprintf(fp, "------------------------\n");
		while(answer->head != answer->tail){
			fprintf(fp, "%d ", answer->head->number);
			answer->head = answer->head->next;
		}
		if(answer->tail != NULL)
			fprintf(fp, "%d ", answer->tail->number);
    	fprintf(fp,"\n");
    	fclose(fp);
    	break;
	}
	answer->head = tmp;
	while(answer->head != answer->tail){
		tmp = answer->head->next;
		free(answer->head);
		answer->head = tmp;
	}
	free(answer->head);
	free(array);
	
	return 0;
}
