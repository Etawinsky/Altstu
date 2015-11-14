#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tree *vt;
struct stack {
    int top;        
    int numbers_size;
    vt *numbers;
};

#include "tree.h"
/* Создаем стек */
void stack_create(struct stack *stacki);

/* Удаляем стек */
void stack_destroy(struct stack *stacki);

/* Впихиваем элемент */
void stack_push(struct stack *stacki, vt number);

/* Выпихиваем элемент */
vt stack_pop(struct stack *stacki);

/* отображаем содержимое верхушки */
vt stack_top(struct stack *stacki);

/* пуст ли стек */
int is_stk_empty(struct stack *stacki);
