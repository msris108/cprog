#include<stdio.h>
#include<stdlib.h>

/*--------------DATA STRUCTURES-------------------*/

typedef struct
{
	int numCities;
	int adjMat[100][100];
	char cities[20][100];
}graphADT;

/*-------------------------------------------------------------------*/

graphADT* setGraph(graphADT *G)
{
	G = (graphADT*) malloc(sizeof(graphADT));
	printf("\nEnter the Number of cities: ");
	scanf("%d", &G->numCities);

	//Name initialization
	for(int i=0;i<G->numCities;i++)
	{
		printf("Enter City name: ");
		scanf("%s", G->cities[i]);
	}
	//Connections
	printf("\n\n***Connections***\n\n");
	printf("Is the graph weighted or unweighted? [1] or [0]? ");
	int ch;
	scanf("%d", &ch);

	for(int i=0;i<G->numCities;i++)
	{
		for(int j=0;j<G->numCities;j++)
		{
			printf("Is %s connected to %s ? [1] or [0]? ", G->cities[i], G->cities[j]);
			scanf("%d", &G->adjMat[i][j]);
			if(G->adjMat[i][j] && ch)
			{
				printf("Enter the cost of the path: ");
				scanf("%d", &G->adjMat[i][j]);
			}
		}
	}
	return G;
}

void displayGraph(graphADT *G)
{
	printf("\nAdjacency Matrix: \n\n");

	for(int i=0;i<G->numCities;i++)
		printf("\t%s", G->cities[i]);

	printf("\n");

	for(int i=0;i<G->numCities;i++)
	{
		printf("%s", G->cities[i]);
		for(int j=0;j<G->numCities;j++)
		{
			printf("\t%d", G->adjMat[i][j]);
		}
		printf("\n");
	}
}

void displayCities(graphADT *G)
{
	printf("\nCities: \n");
	for(int i=0;i<G->numCities;i++)
	{
		printf("%d.%s\n", i+1, G->cities[i]);
	}
}

int hasUnvisited(int visited[], int n)
{
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			return i;
	}

	return -1;
}

int hasUnvisitedNeighbour(int visited[], graphADT *G, int src)
{
	for(int i=0;i<G->numCities;i++)
	{
		if(!(visited[i]) && G->adjMat[src][i])
			return i;
	}

	return -1;
}

int hasUnkown(graphADT *G, int  d[], int k[])
{
	int min=99999, pos =-1;
	for(int i=0;i<G->numCities;i++)
	{
		if(k[i]==0 && d[i]<min)
		{
			min = d[i];
			pos = i;
		}
	}

	return pos;
}

void displayTable(graphADT *g,int d[],int v[], int k[])
{
	printf("\nvert\tk\td\tv\n_________________________\n");
	for(int i=0;i<g->numCities;++i)
	{
		printf("%s\t%d\t%d\t",g->cities[i],k[i],d[i]);
		if(v[i]!=-1)
			printf("%s\n",g->cities[v[i]]);
		else
			printf("-\n");
	}
}

void DSP(graphADT *G,int src)
{
	int k[50],d[50],v[50];

	//initialize
	for(int i=0;i<G->numCities;i++)
	{
		v[i] = -1;
		k[i] = 0;
		d[i] = 999;
	}

	d[src] = 0;
	v[src] = src;

	displayTable(G,d,v,k);
	int x,y;
	for(x=src; x!=-1 ; x=hasUnkown(G,d,k))
	{
		k[x] = 1;
		int visited[50] = {0};
		for(y=hasUnvisitedNeighbour(visited, G, x); y!=-1 ;y=hasUnvisitedNeighbour(visited, G, x))
		{
			visited[y] = 1;
			if(G->adjMat[x][y]+d[x] < d[y])
			{
				d[y] = G->adjMat[x][y]+d[x];
				v[y] = x;
				displayTable(G,d,v,k);
			}
		}
	}
}


void main()
{
	graphADT *G;

	G = setGraph(G);
	displayGraph(G);
	//DFS(G);
	//printf("\n");
	//BFS(G);
	DSP(G, 0);
}