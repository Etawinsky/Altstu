/* list.c */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "list.h"

/* Сощдаем новый список */
struct List *list_init(void)
{
	struct List* theList = malloc(sizeof(struct List));
	assert(theList != NULL);

	theList->head = NULL;
	theList->tail = NULL;
	return theList;
}

/* Добавляем в конец списка */
void list_insert(struct List *test, int number)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	assert(newNode != NULL);
	newNode->number = number;
	newNode->next = NULL;
	if(test->head == NULL){
		test->head = test->tail = newNode;
		test->tail->next = test->head;
	}else{
		test->tail->next = newNode;
		test->tail = newNode;
		test->tail->next = test->head;
	}
}
/* Вставка элементов в список */
struct List *instosrt(struct List *list, int *array, int arraysize)
{
	struct Node *tmp = list->head;
	int i;
	for(i = 0; i < arraysize; i++){
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->number = array[i];

	while(1){
		/* список пуст?...*/
		if(list->head == NULL){
			list->head = list->tail = newNode;
			list->tail->next = list->head;
			tmp = newNode;
			break;
		}
		/*...начало списка?... */
		if(list->head->number > array[i]){
			newNode->next = list->head;
			list->tail->next = newNode;
			list->head = newNode;
			tmp = newNode;
			break;
		}
		/*...середина списка?...*/
		if(list->head->next->number > array[i] ){
			newNode->next = list->head->next;
			list->head->next = newNode;
			break;
		}
		/*...конец списка? */
		if(list->head == list->tail && list->head->number <= array[i] ){
			newNode->next = list->head->next;
			list->head->next = newNode;
			list->tail = newNode;
			list->tail->next = tmp;
			break;	
		}
		list->head = list->head->next;
	}
	/* указатель головы указывает на начало */
	list->head = tmp;	
	}

	return list;
}

