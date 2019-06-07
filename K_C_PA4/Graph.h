//Graph.h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include<queue>
#include <cstdlib>
class Graph
{
public:
	Graph();//constructor
	int num_vert,num_edge,direct_num,start_vert;//declarations
	std::vector<std::vector<std::string> > adjacencyList;//Graph
	void readGraph(std::string);//build graph
	void bfs(int);//breath first search
	void Prim(int);//find min spanning tree
	void assignLow(int);//find articulation points
	void SSP(int);//find min path for all nodes from give node
	void sort();//sort adjacencyList by weight
	~Graph();//deconstructor
};
#endif

