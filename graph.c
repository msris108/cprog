#include<stdio.h>
#include<stdlib.h>
#include "stackADT.h"
#include "queueADT.h"
#include "graphADT.h"


void main()
{
	graphADT *G;

	G = setGraph(G);
	displayGraph(G);
	//DFS(G);
	//printf("\n");
	//BFS(G);
	Dijkstra(G);
}