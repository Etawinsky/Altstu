/* list.h */

 struct Node{
	int number;
	struct Node *next;
	struct Node *previous;
};

struct List{
	struct Node *head;
	struct Node *tail;
};

struct List *list_init(void);
void list_append(struct List *test, int number);
struct List *list_LIS(struct List *test);
struct List *list_insert(struct List *test, struct List *ap, int pos);
void list_push(struct List *test, int number);
