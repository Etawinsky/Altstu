struct queue{
    int left;
    int right;
    int size;
    int *numbers; 
};

void queue_create(struct queue *queuei, int size);
void queue_destroy(struct queue *queuei);
void queue_push(struct queue *queuei, int number);
int queue_pop(struct queue *queuei);
