/* Задание 24.  В массиве А(n) наименьший элемент поместить на первое место,
    наименьший из оставшихся  - на последние место, следующий по величине  - на второе место, 
    следующий  -  на предпоследнее, и  так далее - до середины массива 
    */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_usage();
void swap(int *a, int *b);

int main(int argc, char *argv[])
{
    /* принимаем только один аргумент, иначе - выход из программы */
    if(argc != 2){
        print_usage();
        exit(1);
    }

    int readfrom; 
    int option;

    /* проверяем аргумент*/
    while((option = getopt (argc, argv, "kfh")) != -1){
        switch(option){
            case 'k':
                readfrom = 0;
                break;
            case 'f':
                readfrom = 1;
                break;
            case 'h':
            default: 
                print_usage();
                exit(1);
        }
    }

    int c, i, j, k, tmp, flag, arraysize;
    FILE *fp;
    arraysize = 0;
    int *array = (int *) malloc(arraysize * sizeof(int));
    /* инициализируем массив  */
    for(i=0; i< arraysize; i++)
        array[i] = 0;
    
    i = 0;
    if(readfrom == 0){
        int n, offset;      /* все вот это нужно для того, чтобы окончить ввод символом '\n' */
        char line[1024];
        printf("введите числа: \n");
        fgets(line, 1024, stdin);
        char *p = line;
        while(sscanf(p, "  %d%n", &c, &n) == 1 ){
            if(i == arraysize){
                array = (int *) realloc(array, (arraysize+1) * sizeof(int)); /* увеличим массив, если не хватает места*/
                if(array == NULL){
                    printf("Не смог выделить память");
                    exit(1);
                }
                arraysize++;
            }
            array[i++] = c;
            p += n;
        }   
    } else if (readfrom == 1){
        char filename[20];
        printf("введите имя файла: ");
        scanf("%s", filename);
       
       if((fp=fopen(filename, "r")) == NULL){
            printf("нет такого файла\n");
            exit(1);
        }
        
        while((fscanf(fp, "%d", &c)) != EOF){
            if(i == arraysize){
                array = (int *) realloc(array, (arraysize+1) * sizeof(int));
                if(array == NULL){
                    printf("Не смог выделить память");
                    exit(1);
                }
                arraysize++;
            }
            array[i++] = c;
        }
        while ((c = getchar()) != '\n' && c != EOF); /* отсеять всякий мусор */
        fclose(fp);
     }
    
    flag = i = 0;
    j = arraysize - 1;
    while(i <= arraysize/2){
        c = array[i];
        tmp = i;
        for(k = i+1; k < j+1; k++)
            if(c > array[k]){
                    tmp = k;
                    c = array[k];
                }
        if(flag == 0){
            swap(&array[i], &array[tmp]);
            i++;
            flag = 1;
        } else if(flag == 1){
            swap(&array[j], &array[tmp]);
            j--;
            flag = 0;  
        }
    }
 
     for(i = 0; i < arraysize; i++)
        printf("%d ", array[i]);
    printf("\n");
    printf("Сохранить в файл? [y/n]:");
    scanf("%c", &c);                       /* пропустить пробелы и получить ответ */
    switch (c){
        case 'y': case 'Y': 
            printf("Записано в \"output.txt\"\n");
            fp = fopen("output.txt", "a");
            fprintf(fp, "------------------------\n");
            for(i = 0; i < arraysize; i++)
                fprintf(fp, "%d ", array[i]);
            fprintf(fp,"\n");
            fclose(fp);
            break;
    }
    free(array);
}

void print_usage()
{
    printf("Как использовать:\n\
    -k: ввод с клавиатуры\n\
    -f: ввод из файла\n");

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
