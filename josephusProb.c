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
	q->capacity = capacity;
	q->front = q->size = 0;
	q->rear = q->capacity - 1;
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
		q->front = (q->front + 1) % q->capacity;
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
	int n;

	printf("Enter the number of people:");
	scanf("%d", &n);
	q = initializeQueue(n);

	for(int i=0;i<n;i++)
	{
		enqueue(q, i+1);
	}

	display(q);

	int m;
	printf("Enter the number of steps: ");
	scanf("%d", &m);

	int pop;
	while(!isEmpty(q))
	{
		pop = 0;
		if(q->size == 1) break; 
		for(int i=0;i<m;i++)
		{
			pop = dequeue(q);
			enqueue(q, pop);
		}
		pop = dequeue(q);
	}

	printf("Winner is: %d", dispRear(q));
}