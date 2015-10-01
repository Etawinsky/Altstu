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
	if(test->head == NULL)
		test->head = test->tail = newNode;
	else{
		test->tail->next = newNode;
		test->tail = newNode;
	}
}

/* Добавляем в начало списка */
void list_push(struct List *test, int number)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->number = number;
	newNode->next = NULL;	
	if(test->head == NULL)
		test->head = test->tail = newNode;
	else{
		newNode->next = test->head;
		test->head = newNode;
	}
}

/* Обрабатываем список  */
struct List *list_LIS(struct List *test)
{
	int *prev = NULL;
	int *len = NULL;
	struct Node *tmp = test->head;
	struct Node *first = NULL;
	struct List *answer = NULL;
	answer = list_init();
	int i,j, n;
	int pos, length;
	length = i =  0;

	/* пуст ли список? */

	if(tmp == NULL)
		return answer;	
	while(tmp != NULL){

		/* выделить память под очередные элементы массива*/
		prev = realloc(prev, (++length) * sizeof(int));
		len = realloc(len, (++length) * sizeof(int));
		/* запомнить позицию головы */
		first = test->head;
		prev[i] = -1;
		len[i] = j = 0;

		/* находим количество элементов меньше определенного */
		while(first != tmp){
			if(first->number <= tmp->number &&
			len[j] + 1 > len[i]){
				len[i] = len[j] + 1; 
				prev[i] = j;
			}
			first = first->next;
			j++;
		}
		/* printf("%d --- %d --- %d\n", len[i], tmp->number, prev[i]);*/
		tmp = tmp->next;
		i++;
	}
	/* находим самую длинную последовательность чисел... */
	n = length;
	pos = 0;
	length = len[0];
	for(i = 0; i < n; i++)
		if(len[i] > length){
			pos = i;
			length = len[i];
		}

	tmp = test->head;
	i = 0;
	/* ...и пихаем ее в список */
	while(pos != -1){
		for(i = 0; i < pos; i++)
			tmp = tmp->next;
		list_push(answer, tmp->number);
		pos = prev[pos];
		tmp = test->head;
	}

	return answer;
}
