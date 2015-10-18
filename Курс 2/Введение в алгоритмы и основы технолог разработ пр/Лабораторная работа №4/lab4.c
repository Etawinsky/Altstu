/* Вставить вместо элемента с заданным значением новый список */
#include <stdio.h>
#include "list.h"
#define LINELENGTH 1024
int main()
{

	FILE *fp;
    char line[LINELENGTH];
    char *p;
	int c, n;
	char anw;
	struct List *test = NULL;
	struct List *answer = NULL;
	struct List *combined = NULL;
	test = list_init();
	answer = list_init();
	combined = list_init();
   
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
			list_append(answer, c);
             p +=n;
        }
    }
	fclose(fp);
	printf("введите позицию для вставки:");
		scanf("%d", &c);
	combined = list_insert(test,answer, c);
/*
	while(combined->head != NULL){
		printf("%d ",combined->head->number);	
		combined->head = combined->head->next;
	}
	printf("\n");
	while(combined->tail != NULL){
		printf("%d ",combined->tail->number);	
		combined->tail = combined->tail->previous;
	}
	printf("\n");

*/

	while ((anw = getchar())!= '\n' && anw != EOF);
	printf("Сохранить в файл? [y/n]:");
	scanf("%c", &anw);
	switch (anw){
    	case 'y': case 'Y': 
    	fp = fopen("output.txt", "a");
    	fprintf(fp, "------------------------\n");
		while(combined->head != NULL){
			fprintf(fp, "%d ", combined->head->number);
			combined->head = combined->head->next;
		}
    	fprintf(fp,"\n");
    	fclose(fp);
    	break;
	}

	return 0;
}
