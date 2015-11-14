/* tree.c */
#include "stack.h"
#include <string.h>
struct tree *tree_init(void)
{
	struct tree *thetree = malloc(sizeof(struct tree));
	assert(thetree != NULL);
	thetree->left = NULL;
	thetree->right = NULL;
	return thetree;
}


/*	Функция для преобразования агебраического выражения в дерево
 	Для преобразования используется алгоритм сортировочной станции, разработанный 
	Э. Дейкстрой: 
		* читаем токен
		* если токен - число, то создаем из него новый узел дерева и засовываем его в стек операндов;
		* если токен - оператор оп1
			* 	Пока присутствует на вершине стека операторов токен оператор oп2, и 
				приоритет oп1 меньше оп2
				вытащить оп2 из стека операторов, вытащить два операнда из стека операндов, сделав их сыновьями оп2;
				Положить оп2 в стек операандов
			*	Положить оп1 стек операторов;
		* Если токен — открывающая скобка, то положить его в стек операторов;
		* Если токен — закрывающая скобка:
			*	Пока токен на вершине стека операндов не является открывающей скобкой,
				вытаскивать элементы из обоих стеков и создавать новые поддеревья(см. выше).
			*	Выкинуть открывающую скобку из стека, но не добавлять в стек операндов.
			*	Если стек закончился до того, как был встречен токен открывающая скобка, то в выражении пропущена скобка.
		* Если больше не осталось токенов на входе:
			*	Пока есть токены операторы в стеке:
					Если токен оператор на вершине стека — скобка, 
					то в выражении присутствует незакрытая скобка.
					Создать новое поддерево.

		* Конец.
 */

struct tree *infixtotree(char *expr, struct tree* thetree)
{
	int i;

	struct stack output ;
	struct stack operators;
	
	stack_create(&output);
	stack_create(&operators);

	for(i = 0; i < strlen(expr) -1; i++){
		if(expr[i] >='0' && expr[i] <= '9'){
			thetree = tree_init();
			thetree->data = expr[i];
			thetree->left = thetree->right = NULL;
			stack_push(&output, thetree);
		}if(expr[i] == '('){
			thetree = tree_init();
			thetree->data = expr[i];
			thetree->left = thetree->right = NULL;
			stack_push(&operators, thetree);
		}if(expr[i] == ')'){
				if(is_stk_empty(&operators)){
					assert(is_stk_empty(&output));
					thetree = stack_top(&output);
					assert(is_stk_empty(&output));
					
				}
			while(stack_top(&operators)->data != '('){
				assert(!is_stk_empty(&operators));
				thetree = nd(&operators, &output, thetree);
				assert(!is_stk_empty(&operators));
			}
			stack_pop(&operators);
		}
		if(isop(expr[i])){
			if(!is_stk_empty(&operators)){
				while(isop(stack_top(&operators)->data) && \
				(priority(expr[i], stack_top(&operators)->data) >= 0)){
					thetree = nd(&operators, &output, thetree);
				}
			}

		thetree = tree_init();
		thetree->data = expr[i];
		thetree->left = thetree->right = NULL;
			stack_push(&operators, thetree);
		}
	}
	assert(!is_stk_empty(&output));
	thetree = stack_top(&output);
	while(!is_stk_empty(&operators)){
		assert(!is_stk_empty(&operators));
		thetree = nd(&operators, &output, thetree);
	}
	stack_destroy(&output);
	stack_destroy(&operators);
	return thetree;
}

/* Функция для создания поддерева */
struct tree *nd(struct stack *operators, struct stack *output, struct tree *thetree)
{
	thetree = stack_pop(operators);
	//thetree->right = tree_init();
	thetree->right = stack_pop(output);
	//thetree->left = tree_init();
	assert(!is_stk_empty(output));
	thetree->left = stack_pop(output);
	stack_push(output, thetree);
	return thetree;
}


