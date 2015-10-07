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
struct List *list_LIS(struct List *test);
void list_push(struct List *test, int number);
