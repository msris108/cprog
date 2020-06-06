#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int element;
	struct Node *next;
}node;

typedef struct
{
	node *data[10];
	int size;
}ht;

//------------------------------------

ht* initHT(ht *h, int size)
{
	h = (ht*)malloc(sizeof(ht));
	h->size = size;
	
	for(int i=0;i<size;i++)
	{
		h->data[i] = (node*) malloc(sizeof(node));
		h->data[i]->next = NULL;
	}

	return h;
}

void insert(ht *h, int x)
{
	int hash;
	hash = x%h->size;

	node *temp = (node*) malloc(sizeof(node));
	temp->element = x;
	temp->next = NULL;

	temp->next = h->data[hash]->next;
	h->data[hash]->next = temp;
}

void display(ht *h)
{
	node *temp;
	for(int i=0;i<h->size;i++)
	{
		printf("Elements of the Index %d: ", i);
		temp = h->data[i]->next;

		while(temp != NULL)
		{
			if(temp->next == NULL)	
				printf("%d", temp->element);

			else	
				printf("%d->", temp->element);
			
			temp = temp->next;
		}
		printf("\n");
	}
}

void search(ht *h, int x)
{
	//display(h);
	int flag = 0;
	int hash = x%h->size;
	node *temp = h->data[hash]->next;

	while(temp != NULL)
	{
		if(temp->element == x)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}

	if(flag == 1) printf("FOUND\n");
	else printf("NOT FOUND\n");
}

void main()
{
	ht *h;
	h = initHT(h,10);
	
	for(int i=0;i<10;i++)
		insert(h,i);

	for(int i=0;i<10;i++)
		insert(h,i+10);

	for(int i=0;i<10;i++)
		insert(h,i+20);

	display(h);

	search(h,45);

}