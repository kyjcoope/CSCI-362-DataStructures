//main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Graph.h"

int main(int argc, char* argv[])//get arguments from user
{
	int i = atoi(argv[2]);//convert user agrument to int
	Graph *G = new Graph;//create G
	G->readGraph(argv[1]);//build adjacencyList
	G->bfs(i);//breath first search
	G->Prim(i);//find spanning tree
	G->assignLow(i);//find articulation points
	G->SSP(i);//find sortest path for all
	delete G;//clean up
    return 0;
}

