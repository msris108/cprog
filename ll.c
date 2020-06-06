#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

void insertFront(node *list,int data)
{
	node *temp;

	temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->next = list->next;
	list->next = temp; 
}

void insertEnd(node *list,int data)
{
	node *temp;

	temp = (node*) malloc(sizeof(node));
	temp = list->next;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	node *newNode;

	newNode = (node *)malloc (sizeof(node));

	newNode->data = data;
	temp->next = newNode;
	newNode->next = NULL;
}

void insertAfter(node *list, int target, int data)
{
	node *temp,*newNode;
	int count;

	temp = (node *)malloc(sizeof(node));
	newNode = (node *)malloc(sizeof(node));

	temp = list;
	while(temp != NULL)
	{
		if(temp->data == target)
		{
			newNode->data = data;
			newNode->next = temp->next;
			temp->next = newNode;
		}
		else
		{
			//printf("Element not found");
		}
		temp = temp->next;
	}
}

void delete(node *list, int data)
{
	node *temp;
	temp = (node*) malloc(sizeof(node));
	temp = list;
	while(temp->next != NULL)
	{
		if((temp->next)->data == data)
		{
			temp->next = (temp->next)->next;
		}
		temp = temp->next;
	}
}

void displayList(node* list)
{
	node *temp;
	temp = (node*) malloc(sizeof(node));

	temp = list->next;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void main()
{
	node *list;
	list = (node*) malloc(sizeof(node));
	list->next = NULL;
	list->data = 0;

	insertFront(list, 55);
	insertFront(list, 66);
	insertFront(list, 77);
	insertEnd(list, 99);
	insertAfter(list, 66, 444);
	delete(list, 55);

	displayList(list);
}