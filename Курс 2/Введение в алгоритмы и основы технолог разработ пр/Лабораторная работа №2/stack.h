struct stack {
    int top;        
    int numbers_size;
    int *numbers;
};
/* Создаем стек */
void stack_create(struct stack *stacki);

/* Удаляем стек */
void stack_destroy(struct stack *stacki);

/* Впихиваем элемент */
void stack_push(struct stack *stacki, int number);

/* Выпихиваем элемент */
int stack_pop(struct stack *stacki);

int is_stk_empty(struct stack *stacki);
