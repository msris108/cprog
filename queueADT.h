typedef struct
{
	int *a;
	int front;
	int rear;
	int size;
	int capacity;
}queueADT;

queueADT* initQueue(queueADT *Q, int capacity)
{
	//allocate memory for stack
	Q = (queueADT*) malloc(sizeof(queueADT));
	Q->a = (int*) malloc(capacity * sizeof(int));

	Q->capacity = Q->front = Q->rear = -1;
	Q->size = 0;
}

int isQueueEmpty(queueADT *Q)
{
	return (Q->size == 0);
}


int isQueueFull(queueADT *Q)
{
	return (Q->size == Q->capacity);
}

int dequeue(queueADT *Q)
{
	int temp=-1;
	if(isQueueEmpty(Q))
	{
		printf("queue is empty");
	}

	else
	{
		temp = Q->a[Q->front];
		Q->front++;
		Q->size--;
	}

	return temp;
}

void enqueue(queueADT *Q, int x)
{
	if(isQueueFull(Q))
	{
		printf("queue is full");
	}

	else
	{
		if(Q->front == -1)
			Q->front++;
		Q->a[++Q->rear] = x;
		Q->size++;
	}
}