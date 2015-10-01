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
 
	answer = list_LIS(test);
	fclose(fp);

	while ((c = getchar())!= '\n' && c != EOF);/* отсеять всякий мусор */
	printf("Сохранить в файл? [y/n]:");
	scanf("%c", &c);/* пропустить пробелы и получить ответ */
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

	return 0;
}
