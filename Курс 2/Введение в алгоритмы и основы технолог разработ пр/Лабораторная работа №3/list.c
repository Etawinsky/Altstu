/* list.c */
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct List *list_init(void)
{
	struct List* theList = malloc(sizeof(struct List));
	assert(theList != NULL);

	theList->head = NULL;
	theList->tail = NULL;
	return theList;
}

void list_insert(struct List *test, int number)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	assert(newNode != NULL);
	newNode->number = number;
	newNode->next = NULL;
	if(test->head == NULL)
		test->head = test->tail = newNode;
	else{
		test->tail->next = newNode;
		test->tail = newNode;
	}
}
