
#include "stack.h"
int isop(char op);
int priority(char op1, char op2);
void reptree(struct tree *thetree);
void nonreptree(struct tree *thetree);
int main()
{
	
	struct tree *thetree = NULL;
	thetree = tree_init();
	thetree = infixtotree("(4*((2+2)-2)+1)*2", thetree);

	//reptree(thetree);
	nonreptree(thetree);
	printf("\n");
	return 0;

}

void reptree(struct tree *thetree)
{
	if(thetree != NULL){
		if(isop(thetree->data))
			printf("(");
		reptree(thetree->left);
		printf("%c", thetree->data);
		reptree(thetree->right);
		if(isop(thetree->data))
			printf(")");
	}
}

int isop(char op)
{
	return op == '+' || op == '*' || op == '-' || op == '/' || op == '^';
}

int priority(char op1, char op2)
{
	if((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/' || op2 == '^'))
		return 1;
	else if((op1 == '*' || op1 == '/' || op1 == '^') && (op2 == '+' || op2 == '-'))
		return -1;
	else 
		return 0;
}

void nonreptree(struct tree *thetree)
{
 /* set current to root of binary tree */
  	struct tree *current = thetree;
  	struct stack buf;  /* Initialize stack s */
	stack_create(&buf);
	int done = 0;
 
  while (!done)
  {
    /* Reach the left most tNode of the current tNode */
    if(current !=  NULL)
    {
		if(isop(current->data))
			printf("(");
      stack_push(&buf, *current);
      current = current->left;  
    }
    else
    {
      if (!is_stk_empty(&buf))
      {
		current = tree_init();
        *current = stack_pop(&buf);
		if(isop(current->data))
			if(isop(current->left->data) || !isop( current->right->data) ){
				printf(")");
				printf("---='%c'\n", current->data);

			}
		printf("%c", current->data);
 
        /* we have visited the node and its left subtree.
          Now, it's right subtree's turn */
		current = current->right;
      }
      else
        done = 1; 
    }
  }

}
