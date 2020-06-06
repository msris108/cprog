/*--------------DATA STRUCTURES and  MISC methods-------------------*/

typedef struct
{
	int numCities;
	int adjMat[100][100];
	char cities[20][100];
}graphADT;

int min(int a,int b){
	return a<b?a:b;
}

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

int unvisited(int visited[], int n)
{
	for(int i=0;i<n;i++)
		if(visited[i] == 0)
			return i;

	return -1;
}

int unvisitedMin(int visited[],int distance[], int n)
{
	int min = 99999;
	for(int i=0;i<n;i++)
		if(visited[i] == 0 && distance[i] < min)
			min = i;

	return min;
}

int unvisitedNeighbour(int visited[], graphADT *G, int src)
{
	for(int i=0;i<G->numCities;i++)
	{
		if(G->adjMat[src][i] && !(visited[i]))
			return i;
	}

	return -1;
}

int unvisitedMinNeighbour(int visited[],int distance[], graphADT *G, int src)
{
	int min = 99999;
	for(int i=0;i<G->numCities;i++)
	{
		if(G->adjMat[src][i] && !(visited[i]) && distance[i] < min)
			min = i;
	}

	return min;
}

void DFS(graphADT *G)
{
	//stack initialization
	stackADT *S;
	S = initStack(S, 100);

	printf("\nDepth First Search:\n");
	displayCities(G);
	
	int src;
	printf("\nEnter Source Index: ");
	scanf("%d", &src);
	src--;

	int visited[G->numCities];
	for(int i=0;i<G->numCities;i++)
		visited[i] = 0;

	int x,y,z;
	for(x = unvisited(visited, G->numCities); x != -1; x = unvisited(visited, G->numCities))
	{
		visited[x] = 1;
		printf("outVisited %s\n", G->cities[x]);
		push(S,x);
		while(!isStackEmpty(S))
		{
			z = peek(S);
			y = unvisitedNeighbour(visited,G,z);
			//unvisited neighbour of z
			if(y != -1)
			{
				visited[y] = 1;
				printf("inVisited %s\n", G->cities[y]);

				push(S,y);
			}

			else
			{
				pop(S);
			}
		}
	}
}

void BFS(graphADT *G)
{
	//Queue initialization
	queueADT *Q;
	Q = initQueue(Q,100);

	printf("\nBreadth First Search:\n");
	displayCities(G);
	
	int src;
	printf("\nEnter Source Index: ");
	scanf("%d", &src);
	src--;

	int visited[G->numCities];
	for(int i=0;i<G->numCities;i++)
		visited[i] = 0;

	int x,y,z;
	for(x = unvisited(visited, G->numCities); x != -1 ;x = unvisited(visited, G->numCities))
	{
		visited[x] = 1;
		printf("outVisited %s\n", G->cities[x]);
		enqueue(Q,x);
		while(!isQueueEmpty(Q))
		{
			z = dequeue(Q);
			//unvisited neighbour of z
			for(y = unvisitedNeighbour(visited,G,z); y != -1; y = unvisitedNeighbour(visited,G,z))
			{
				visited[y] = 1;
				printf("inVisited %s\n", G->cities[y]);
				enqueue(Q,y);
			}
		}
	}
}

void Dijkstra(graphADT *G)
{
	int inf = 9999;//inital value

	displayCities(G);
	int startNode;
	printf("Enter the start Index: ");
	scanf("%d", &startNode);
	startNode--;

	int curr_state = startNode;

	//VKDP initiallization
	int visited[G->numCities];
	int distance[G->numCities];
	int path[G->numCities];

	visited[startNode] = 1;
	distance[startNode] = 0;
	path[startNode] = startNode;

	for(int i=0;i<G->numCities;i++)
	{
		visited[i] = 0;
		distance[i] = inf;
		
		if(adjMat[startNode][i] != 0)
			path[i] = adjMat[startNode][i];
		else
			path[i] = inf;
	}
	
	int x,y,z;

	x = unvisitedNeighbour(visited,G,startNode);

	int i=0;
	while(x != 99999)
	{
		visited[x] = 1;
		if (distance[x] > G->adjMat[x][path[x]] + G->adjMat[path[x]][x])
		{

		}
		x = unvisitedMinNeighbour()
	}

	printf("\n\nVertex\tKnown\tDist\tPath\n");
	printf("-------------------------------");
	for(int i=0;i<G->numCities;i++)
	{
		printf("\n%s\t%d\t%d\t%d", G->cities[i], visited[i], distance[i], path[i]);
	}
}