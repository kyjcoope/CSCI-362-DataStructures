/*HOW TO COMPILE*/
To compile graph make sure to move Makefile and all source files into the same directory
Type>> make

To run the files after they are compiled
Type>> ./graph <input file> <node number>

<input file>: must be a .txt file, and is the file you want graphed, example: input.txt
<node number>: must be an integer

To remove all .o files
Type>> make clean

/*FUNCTIONS AND CLASS DESTRIPTIONS*/
main.cpp
creates G and runs methods of G

Graph.h
holds all declarations for methods and variables used in Graph.cpp

Graph.cpp
	void Graph::readGraph(std::string input)
		builds graph

	void Graph::bfs(int num)
		breath first search

	void Graph::Prim(int num)
		find min spanning tree
	
	void Graph::assignLow(int)
		find articulation points

	void Graph::SSP(int)
		find sortest path

	void Graph::sort()
		sorts adjacencyList by weight












