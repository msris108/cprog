typedef struct
{
	int *a;
	int top;
	int capacity;
}stackADT;

stackADT* initStack(stackADT *S, int capacity)
{
	//allocate memory for stack
	S = (stackADT*) malloc(sizeof(stackADT));
	S->a = (int*) malloc(capacity * sizeof(int));

	S->capacity = capacity;
	S->top = -1;
}

int isStackEmpty(stackADT *S)
{
	return (S->top == -1);
}


int isStackFull(stackADT *S)
{
	return (S->top == S->capacity-1);
}

int peek(stackADT *S)
{
	if(isStackEmpty(S))
		return(-1);
	else	
		return(S->a[S->top]);
}

void pop(stackADT *S)
{
	if(isStackEmpty(S))
		printf("Stack is empty");

	else
		S->top--;
}

void push(stackADT *S, int x)
{
	if(isStackFull(S))
		printf("Stack is full");

	else
		S->a[++S->top] = x;
}

void dispStack(stackADT *S)
{
	for(int i=0;i<S->top+1;i++)
	{
		printf("%d", S->a[i]);
	}

	printf("\nstack size: %d", &S->top+1);
}