#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_SIXE 100

typedef struct 
{
	int front, rear;
	int size;
	unsigned capacity;
	int *data;
}queue;

queue* initializeQueue(int capacity)
{
	queue *q = (queue *) malloc(sizeof(queue));
	q->front = q->size = 0;;
	q->rear = q->capacity - 1;
	q->capacity = capacity;
	q->data = (int*) malloc(q->capacity * sizeof(int));
	return q;
}

int isEmpty(queue *q)
{
	return (q->size == 0);
}

int isFull(queue *q)
{
	return (q->size == q->capacity);
}

void enqueue(queue *q, int data)
{
	if(isFull(q))
	{
		printf("Queue is Full");
	}
	else
	{
		q->rear = (q->rear + 1) % q->capacity;
		q->data[q->rear] = data;
		q->size++;
	}
}

int dequeue(queue *q)
{
	if(isEmpty(q))
	{
		printf("Queue is Empty");
		return INT_MIN;
	}
	else
	{
		int item = q->data[q->front];
		q->front = (q-> front + 1) % q->capacity;
		q->size--;
		return item;
	}
}

int dispFront(queue *q)
{
	return q->data[q->front];
}

int dispRear(queue *q)
{
	return q->data[q->rear];
}

void display(queue *q)
{
	printf("Elements:");
	for(int i=0;i<q->size;i++)
	{
		printf("%d ", q->data[i]);
	}
}

void main()
{
	queue *q;
	q = initializeQueue(20);

	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);

	printf("The element popped out is %d", dequeue(q));

	printf("\nThe element in the front is: %d", dispFront(q));
	printf("\nThe element in the rear is: %d", dispRear(q));
}