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

struct tree *infixtotree(char *expr, struct tree* thetree)
{
	int i;

	struct stack output ;
	struct stack operators;
	
	stack_create(&output);
	stack_create(&operators);

	for(i = 0; i < strlen(expr); i++){
		thetree->data = expr[i];
		thetree->left = thetree->right = NULL;
		if(expr[i] >='0' && expr[i] <= '9')
			stack_push(&output, *thetree);
		if(expr[i] == '(')
			stack_push(&operators, *thetree);
		if(expr[i] == ')'){
			while(stack_top(&operators).data != '('){
				if(is_stk_empty(&operators)){
					fprintf(stderr,"Не хватает скобки\n");
					return NULL;
				}
				nd(&operators, &output, thetree);
			}
			stack_pop(&operators);
		}
		if(isop(expr[i])){
			if(!is_stk_empty(&operators)){
				while(isop(stack_top(&operators).data) && \
				(priority(expr[i], stack_top(&operators).data) >= 0)){
					nd(&operators, &output, thetree);
				}
			}

		thetree->data = expr[i];
		thetree->left = thetree->right = NULL;
			stack_push(&operators, *thetree);
		}
	}
	while(!is_stk_empty(&operators)){
		if(is_stk_empty(&operators)){
			fprintf(stderr,"Не хватает скобки\n");
			return NULL;
		}
		nd(&operators, &output, thetree);
			}
	stack_destroy(&output);
	stack_destroy(&operators);
	return thetree;
}

void nd(struct stack *operators, struct stack *output, struct tree *thetree)
{
	*thetree = stack_pop(operators);
	thetree->right = tree_init();
	*thetree->right = stack_pop(output);
	thetree->left = tree_init();
	if(is_stk_empty(output))
		fprintf(stderr,"ЕГГОГ\n");
	*thetree->left = stack_pop(output);
	stack_push(output, *thetree);
}


