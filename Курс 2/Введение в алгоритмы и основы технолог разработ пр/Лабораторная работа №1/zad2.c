/* Задание 40. Получить очередь из минимальных соотвествующих элементов исходных стеков */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define STACK_SIZE 10
typedef int StackElement;
void print_usage();
void swap(int *a, int *b);

typedef struct{
    StackElement *contents;
    int top;
    int maxSize;
}stackT;

void StackDestroy(stackT *stackP);
void StackInit(stackT *stackP, int maxSize);
int StackIsEmpty(stackT *stackP);
int StackIsFull(stackT *stackP);
void StackPush(stackT *stackP, StackElement element);
StackElement StackPop(stackT *stackP);
int main(int argc, char *argv[])
{
    /* принимаем только один аргумент, иначе - выход из программы */
    if(argc != 2){
        print_usage();
        return 1;
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
                return 1;
        }
    }
    stackT *stacks;
    int arraysize = 10;
    int c, n, i,j;
    int *tmp = (int *)malloc(10 * sizeof(int));
    stacks = (stackT *)malloc(10 * sizeof(stackT));
    if(readfrom == 0){
        int n, offset;      /* все вот это нужно для того, чтобы окончить ввод символом '\n' */
        char line[1024];
        j = 0;
        printf("введите числа: \n");
        while(strcmp(line, "end")){
            fgets(line, 1024, stdin);
            char *p = line;
            while(sscanf(p, "  %d%n", &c, &n) == 1 ){
                if(i == arraysize){
                     tmp = (int *) realloc(tmp, (arraysize+1) * sizeof(int)); /* увеличим массив, если не хватает места*/
                    if(tmp == NULL){
                        printf("Не смог выделить память");
                        exit(1);
                    }
                    arraysize++;
                }
                tmp[i++] = c;
                p += n; 
            }
            StackInit(&stacks[j], arraysize);
            for(i = 0; i < arraysize; i++)
                StackPush(&stacks[j], tmp[i]);
            j++;    
            tmp = (int *) realloc(tmp, (arraysize+1) * sizeof(int)); /* увеличим массив, если не хватает места*/
        }
    }
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


void StackInit(stackT *stackP, int maxSize)
{ 
 StackElement *newContents;
    newContents = (StackElement *)malloc(sizeof(StackElement) * maxSize);

    if(newContents == NULL){
        fprintf(stderr, "Недостаточно памяти для инициализации стека\n");
        exit(1);
    }

    stackP->contents = newContents;
    stackP->maxSize = maxSize;
    stackP->top = -1;
}

void StackDestroy(stackT *stackP)
{
    free(stackP->contents);

    stackP->contents = NULL;
    stackP->maxSize = 0;
    stackP->top = -1;
}
int StackIsEmpty(stackT *stackP)
{
    return stackP->top < 0;
}

int StackIsFull(stackT *stackP)
{
    return stackP->top  >= stackP->maxSize - 1;
}

void StackPush(stackT *stackP, StackElement element)
{
    if(StackIsFull(stackP)){
        fprintf(stderr, "Не могу впихнуть элемент: cтэк полон\n");
        exit(1);
    }

    stackP->contents[++stackP->top] = element;
}

StackElement StackPop(stackT *stackP)
{
    if (StackIsEmpty(stackP)){
        fprintf(stderr, "Не могу вытолкнуть элемент: стек пуст");
        exit(1);
    }

    return stackP->contents[stackP->top--];
}
