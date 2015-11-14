/* Преобразовать алгебраическое выражение в дерево */

#include "stack.h"
#define LINELENGTH 1024
int isop(char op);
int priority(char op1, char op2);
void reptree(struct tree *thetree);
int nonreptree(struct tree *thetree);
int main()
{
	/* открываем файл */
	char line[LINELENGTH];
	FILE *fp;
    printf("введите имя файла:");
    scanf("%s", line);
    if((fp = fopen(line,"r")) == NULL){
        fprintf(stderr, "Нет такого файла\n");
        return 1;
    }
	/* считываем строку */
    fgets (line, LINELENGTH, fp);
	fclose(fp);
	

	/* cоздаем новое дерево */
	struct tree *thetree = NULL;
	thetree = tree_init();
	
	/* преобразуем */
	thetree = infixtotree(line, thetree);

	/* рекурсивная печать дерева*/	
	//reptree(thetree);
	/* нерекурсивная печать дерева */
	nonreptree(thetree);
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

int nonreptree(struct tree *thetree)
{
	FILE *fp;
	fp = fopen("output.txt", "w");
  	
	struct tree *current = thetree;
  	struct stack buf;
	stack_create(&buf);
	int done = 0;

	/* если дерево состоит из единственного элемента */
	if(current !=NULL){
		fprintf(fp,"Л К П\n");
		if( current->left == NULL &&  current->right == NULL ){
	  		fprintf(fp,"  %c", current->data);
			fclose(fp);
			return 1;
		}
	}
  	while (!done){
		/* пока левый потомок не NULL - пихаем элемент в стек */
    	if(current !=  NULL){
      		stack_push(&buf, current);
      		current = current->left;
    	}else{

			if (!is_stk_empty(&buf)){
        		current = stack_pop(&buf);

			if(isop(current->data)){
				if(current->left != NULL)
					fprintf(fp,"%c", current->left->data);
				else
					fprintf(fp," ");

				fprintf(fp," %c", current->data);
				
				if(current->right != NULL)
					fprintf(fp," %c", current->right->data);
				else
					fprintf(fp," ");
				fprintf(fp,"\n");
			}	
			current = current->right;
		}else
			done = 1; /* конец работы */
    }
  }
	fclose(fp);
	return 0;
}
