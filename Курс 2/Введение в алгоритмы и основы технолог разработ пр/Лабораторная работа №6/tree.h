/* tree.h */
typedef char dt;
struct tree{
	dt data;
	struct tree *left;
	struct tree *right;
};

struct tree *tree_init(void);
struct tree *infixtotree(char *expr, struct tree *thetree);
struct tree *nd(struct stack *operators, struct stack *output, struct tree *thetree);
int isop(char op);
int priority(char op1, char op2);
