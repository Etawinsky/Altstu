/* Задание 40. Получить очередь из минимальных соотвествующих элементов исходных стеков */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#define LINELENGTH 1024 /* длина считываемой строки */

int main(int argc, char *argv[]){

    FILE *fp;
    char line[LINELENGTH];
    char *p;;
    int c, n, numofstacks, biggest, tmp,tmp2;
    int i,j;
    struct stack *stacks = NULL;
    printf("введите имя файла:");
    scanf("%s", line);
    if((fp = fopen(line,"r")) == NULL){
        fprintf(stderr, "Нет такого файла\n");
        return 1;
    }
    tmp = 15000; /* костыль */
    biggest = 1;
    /* читаем строку за строкой */
    numofstacks = 0;
    while(fgets (line, LINELENGTH, fp)){
        /* создаем еще один стек */
        stacks = realloc(stacks, (numofstacks+1) * sizeof(struct stack));
        tmp = 0;
        p = line;
         stack_create(&stacks[numofstacks]);
         while(sscanf(p, "  %d%n", &c, &n) == 1 ){
             stack_push(&stacks[numofstacks], c);
             tmp+=1;
             /* все элементы из строки втащили в стек- молодцы */ 
             /* самый ли он большой? */
             if(tmp > biggest)
                 biggest = tmp; 
             p +=n;
        }
         numofstacks++;
    }

    /* считали все стеки, создаем очередь*/
    struct queue oczered;
    queue_create(&oczered, biggest+1); /* костыль */
  for(i = 0; i < biggest; i++){
    tmp = 100500; /* костыль */
       for(j = 0; j < numofstacks; j++){
            if(!is_stk_empty(&stacks[j])){
                tmp2 = stack_pop(&stacks[j]);
               if(tmp > tmp2)
                    tmp = tmp2;
        //       printf("%d ", tmp);
            }
        }
      // printf("\n");
      // printf("%d ---", tmp);
       if(tmp == 100500) /* костыль */ 
           return 1;
        queue_push(&oczered, tmp);
    }
fclose(fp);
while ((c = getchar()) != '\n' && c != EOF); /* отсеять всякий мусор */
printf("Сохранить в файл? [y/n]:");
scanf("%c", &c);                       /* пропустить пробелы и получить ответ */
switch (c){
    case 'y': case 'Y': 
    printf("Записано в \"output.txt\"\n");
    fp = fopen("output.txt", "a");
    fprintf(fp, "------------------------\n");
    for(i = 0; i < biggest; i++)
        fprintf(fp, "%d ", queue_pop(&oczered));
    fprintf(fp,"\n");
    fclose(fp);
    break;
}
/*
  printf("Ответ:\n");
  for(i = 0; i < biggest; i++)
      printf("%d\n", queue_pop(&oczered));
   return 0; 
   */
}

