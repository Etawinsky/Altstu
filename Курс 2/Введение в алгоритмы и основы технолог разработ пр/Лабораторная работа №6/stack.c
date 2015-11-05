
#include "stack.h"
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

void stack_push(struct stack *stacki, vt number)
{
    if(stacki->top == stacki->numbers_size - 1){
        stacki->numbers = realloc(stacki->numbers, (stacki->numbers_size+1) * sizeof(vt));
        if(stacki->numbers == NULL) 
            fprintf(stderr, "Недостаточно памяти");
    }
    /* еще какие проверки, которые я не забыл */
    stacki->numbers[stacki->numbers_size++] = number;
    stacki->top++;
}

vt stack_pop(struct stack *stacki)
{
    if(stacki->top != -1){
		stacki->numbers_size--;
        return stacki->numbers[stacki->top--];
	}
	assert(stacki->top != -1);
	return stacki->numbers[0];

}
vt stack_top(struct stack *stacki)
{
	return stacki->numbers[stacki->top];
}

int is_stk_empty(struct stack *stacki)
{
    if(stacki->top < 0)
        return 1;
    else
        return 0;

}
