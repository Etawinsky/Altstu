/* list.h */

 struct Node{
	int number;
	struct Node *next;
};

struct List{
	struct Node *head;
	struct Node *tail;
};

struct List *list_init(void);
void list_insert(struct List *test, int number);

