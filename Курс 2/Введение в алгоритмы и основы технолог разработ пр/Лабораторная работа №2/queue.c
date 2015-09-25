#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"
void queue_create(struct queue *queuei, int size)
{
    queuei->left = 7;
    queuei->right = 7;
    queuei->size = size ;
    queuei->numbers = malloc(size * sizeof(int));
}

void queue_destroy(struct  queue *queuei)
{
    queuei->left = -1;
    queuei->right = -1;
    queuei->size = -1;
    free(queuei->numbers);
}

void queue_push(struct queue *queuei, int number)
{ 
    assert((queuei->right+1) % queuei->size != queuei->left);
    queuei->numbers[queuei->right] = number;
    queuei->right++;
    queuei->right %= (queuei->size ); 
}
int queue_pop(struct queue *queuei)
{
    assert((queuei->left ) % queuei->size != queuei->right);    
    queuei->left++;
    queuei->left %= queuei->size ;
    return queuei->numbers[queuei->left -1 ];

}
