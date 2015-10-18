/* list.c */
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "list.h"

/* Создаем новый список */
struct List *list_init(void)
{
	struct List* theList = malloc(sizeof(struct List));
	assert(theList != NULL);

	theList->head = NULL;
	theList->tail = NULL;
	return theList;
}
/* 	Функция вставки списка в список, начиная с определенной позиции.
	Если Вставляемый список, список, в который нужно вставить, пусты
  	или позиции для вставки превосходят/меньше размера списка, 
	то возвращается пустой список
 */
struct List *list_insert(struct List *test, struct List *toinsert, int pos)
{
	
	int i;
	struct List *ap = NULL;
	struct Node *tmp= test->head;
	ap = list_init();
	if(test->head == NULL || pos < 0)
		return test;

	for(i = 0; i < pos; i++){
		if(tmp->next == NULL){
			return ap;
		}
		tmp = tmp->next;
	}
	/* Подцепляем "конец" одного списка */
	if(toinsert->head == NULL){
		if(tmp->next !=NULL)
			tmp->next->previous = tmp->previous;
		else
			test->tail = tmp->previous;
		if(tmp->previous != NULL)
			tmp->previous->next = tmp->next;
		else 
			test->head = tmp->next;
		return test;
	}
	ap = toinsert;
	ap->tail->next = tmp->next;

	if(tmp->next != NULL)
		tmp->next->previous = ap->tail;
	/* подцепляем "начало" списка */
	if(tmp->previous != NULL){
		tmp = tmp->previous;
		tmp->next = ap->head;
		ap->head->previous = tmp;
	}else{
		ap->head->previous = NULL;
	}

	/* устанавливаем указатели на начало и конец списка*/
	while(ap->head->previous != NULL)
		ap->head = ap->head->previous;

	while(ap->tail->next != NULL)
		ap->tail = ap->tail->next;

	return ap;
	
}
/* Добавляем в конец списка */
void list_append(struct List *test, int number)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	assert(newNode != NULL);
	newNode->number = number;
	newNode->next = NULL;
	newNode->previous = test->tail;
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
