/* Задан список чисел. Образовать из него новый, исключив из исходного
 минимальное число элементов так, чтобы список стал неубывающим */

#include <stdio.h>
#include "list.h"

int main()
{

	struct List *test = NULL;
	test = list_init();
	list_insert(test, 10);
	printf("xbckj %d\n", test->tail->number);
	list_insert(test, 16);
	printf("xbckj %d\n", test->tail->number);
	printf("xbckj %d\n", test->head->number);
	test->head = test->head->next;
	printf("xbckj %d\n", test->head->number);
	return 0;
}
