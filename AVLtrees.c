#include<stdio.h>
#include<stdlib.h>

#define COUNT 5

static int maxOf(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

typedef struct Tree
{
	int data;
	struct Tree *left, *right;
	int height;
}tree;

tree* createNode(tree *t, int data)
{
	t = (tree*) malloc(sizeof(tree));
	t->right = NULL;
	t->left = NULL;
	//printf("INIT DONE\n");
	return t;
}

static int heightOfTree(tree *t)
{
	if(t == NULL)
		return -1;
	else
		return t->height;
}

tree* findNode(tree *t, int data)
{
	if(t == NULL)
		printf("error");
	else if(t->data > data)
		return findNode(t->left, data);
	else if(t->data < data)
		return findNode(t->right, data);
	else
		return t;
}

void displayTree(tree* t, int space)
{
	if(t == NULL) return;

	space += COUNT;

	displayTree(t->right, space);

	printf("\n");
	for(int i=COUNT; i<space ;i++) printf(" ");
	printf("%d", t->data);

	displayTree(t->left, space);
}

tree* findMin(tree *t)
{
	//printf("sd");
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

tree* findMax(tree *t)
{
	if(t == NULL)
		return NULL;
	else if(t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

static tree* singleRotationWithLeft(tree *k2)
{
	tree *k1;

	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = maxOf(heightOfTree(k2->left), heightOfTree(k1->right)) + 1;
	k1->height = maxOf(heightOfTree(k1->left), k2->height) + 1;

	return k1;
}

static tree* singleRotationWithRight(tree *k2)
{
	tree *k1;

	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k2->height = maxOf(heightOfTree(k2->left), heightOfTree(k1->right)) + 1;
	k1->height = maxOf(heightOfTree(k1->right), k2->height) + 1;

	return k1;
}

static tree* doubleRotationWithLeft(tree *k3)
{
	k3->left = singleRotationWithRight(k3->left);

	return singleRotationWithLeft(k3);
}

static tree* doubleRotationWithRight(tree *k3)
{
	k3->right = singleRotationWithLeft(k3->left);

	return singleRotationWithRight(k3);
}

tree* insert(tree *t, int data)
{
	if(t == NULL)
	{
		t = createNode(t, data);
		t->data = data;
		t->height = 0;
		printf("Insert done element:%d\n", data);
	}
	else if(t->data < data)
	{
		//printf("Enter case 1\n");
		t->right = insert(t->right, data);
		if(heightOfTree(t->right) - heightOfTree(t->left) == 2)
			if(t->right->data < data)
				t = singleRotationWithRight(t);
			else
				t = doubleRotationWithRight(t);
	}
	else if(t->data > data)
	{
		//printf("Enter case 2\n");
		t->left = insert(t->left, data);
		if(heightOfTree(t->left) - heightOfTree(t->right) == 2)
			if(t->left->data > data)
				t = singleRotationWithLeft(t);
			else
				t = doubleRotationWithLeft(t);
	}
	t->height = maxOf(heightOfTree(t->left), heightOfTree(t->right)) + 1;
	
	return t;
}

tree* delete(tree *t, int data)
{
	
	tree *temp;
	
	if(t == NULL)
	{
		printf("Error");
	}

	else if(data < t->data)
	{
		//printf("going left");
		t->left = delete(t->left, data);
	}

	else if(data > t->data)
	{
		//printf("going right");
		t->right = delete(t->right, data);
	}

	else
	{
		if(t->left != NULL && t->right != NULL)
		{
			//temp = t;
			//printf("\nEnter two child node\n");
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = delete(t->right, t->data);
		}

		else
		{
			//temp = t;
			if(t->left == NULL)
				t = t->right;
			else if(t->right == NULL)
				t = t->left;
			//free(temp);
		}
	}
	return t;
}

void main()
{
	tree *t;
	t = NULL;

	int flag = 1;
	int tempData; 

	t = insert(t,15);
	t = insert(t,20);
	t = insert(t,24);
	t = insert(t,10);
	t = insert(t,13);
	t = insert(t,7);
	t = insert(t,30);
	t = insert(t,36);
	t = insert(t,25);
	/*t = insert(t,5);
	t = insert(t,9);
	t = insert(t,12);
	t = insert(t,14);
	t = insert(t,16);
	t = insert(t,8);
	t = insert(t,10);*/
	
	displayTree(t,0);
	

	//t = delete(t,2);
	//printf("\n");
	//findNode(t,3);
	//displayTree(findNode(t,3),0);
}