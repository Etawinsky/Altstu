#include <assert.h>
#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

void stack_create(struct stack *stacki)
{
    stacki->top = -1;
    stacki->numbers_size = 0;
    stacki->numbers = NULL; 
}

void stack_destroy(struct stack *stacki)
{
    /* удаляем элементы */

    free(stacki->numbers);
    stacki->numbers = NULL;
    stacki->top = -1;
    stacki->numbers_size = -1; 
}

void stack_push(struct stack *stacki, int number)
{
    if(stacki->top == stacki->numbers_size - 1){
        stacki->numbers = realloc(stacki->numbers, (stacki->numbers_size+1) * sizeof(int));
        if(stacki->numbers == NULL) 
            fprintf(stderr, "Недостаточно памяти");
    }

    /* еще какие проверки, которые я не забыл */
    stacki->numbers[stacki->numbers_size++] = number;
    stacki->top++;
}

int stack_pop(struct stack *stacki)
{
    /* если стек непуст, и не какая-то хрень, то*/
    if(stacki->top != -1)
        return stacki->numbers[stacki->top--];
    else{
        fprintf(stderr, "Cтек пуст");
        return 1;
    } 

    return 0;
}

int is_stk_empty(struct stack *stacki)
{
    if(stacki->top < 0)
        return 1;
    else
        return 0;

}
