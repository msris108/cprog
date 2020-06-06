#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} node;

void insertFront(node *list,int data)
{
	node *temp;

	temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->next = list->next;
	temp->prev = list;
	list->next = temp; 
}

void insertEnd(node *list,int data)
{
	node *temp;

	temp = (node*) malloc(sizeof(node));
	temp = list->next;

	while(temp->next != list)
	{
		temp = temp->next;
	}

	node *newNode;

	newNode = (node *)malloc(sizeof(node));

	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

void insertAfter(node *list, int target, int data)
{
	node *temp,*newNode;
	int count;

	temp = (node *)malloc(sizeof(node));
	newNode = (node *)malloc(sizeof(node));

	temp = list;
	while(temp->next != list)
	{
		if(temp->data == target)
		{
			//printf("found");
			newNode->data = data;
			newNode->next = temp->next;
			newNode->prev = temp;
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
	while(temp->next != list)
	{
		if((temp->next)->data == data)
		{
			temp->next = (temp->next)->next;
			(temp->next)->prev = temp;
		}
		temp = temp->next;
	}
}

void displayList(node* list)
{
	node *temp;
	temp = (node*) malloc(sizeof(node));

	temp = list->next;
	while(temp != list)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void main()
{
	node *list;
	list = (node*) malloc(sizeof(node));
	list->next = list;
	list->prev = list;
	list->data = 0;

	insertFront(list, 55);
	insertFront(list, 66);
	insertFront(list, 77);
	insertEnd(list, 99);
	insertAfter(list, 66, 444);
	delete(list, 55);

	displayList(list);
}