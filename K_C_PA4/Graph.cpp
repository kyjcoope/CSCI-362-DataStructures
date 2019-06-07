//Graph.cpp
#include "Graph.h"
#include <string>
#include <sstream>
Graph::Graph()//constructor
{
}

void Graph::readGraph(std::string input)//builds graph
{
	std::vector<std::string> v;
	std::string line;
	std::ifstream textFile(input.c_str()); //textFile takes first argument of execution command for file name
	if (textFile.is_open()) { //check if able to open file
		std::getline(textFile, line, ' ');//get vertices
		num_vert = atoi(line.c_str());
		std::getline(textFile, line, ' ');//get edges
		num_edge = atoi(line.c_str());
		std::getline(textFile, line); //get directed/undirected
		direct_num = atoi(line.c_str());
		for (int i = 0; i < num_vert; i++) { //get all nodes
			while (textFile.peek() != '\n') {
				getline(textFile, line, ' ');
				v.push_back(line);
				getline(textFile, line, ' ');
				v.push_back(line);
			}
			adjacencyList.push_back(v);
			getline(textFile, line);
			v.erase(v.begin(), v.end());//prep for next node
		}
	}
	else std::cout << "Unable to open file";//failed to open file
	textFile.close(); //close textFile
}
void Graph::bfs(int num)//breath first search
{
	//declarations
	int i = 0,j = 0,k=0,skip=0,v_index= 0,stop=0,first=0;
	std::string a, b,c,str;
	std::vector<std::string> temp;//used as temporary storage
	std::queue <std::string> Q;//queue
	std::vector<std::string> visited;//list of visited nodes
	std::cout << "Breath first search:" << std::endl;
	int number = num - 1;//node correction in vector
	std::stringstream out;
	out << num;
	str = out.str();
	Q.push(str);//push first node to queue
	visited.push_back(str);//add first node to visited
	temp = adjacencyList[number];//used to look at node in adjacencyList
	while (!Q.empty()) {//keep going until queue is empty
		if (first == 1) {//if first run through skip 
			c = Q.front();//looks at front of queue
			temp = adjacencyList[atoi(c.c_str())];//loads front of queue to temp
		}
		first = 1;
		j = 0;//reset j
		
		while (stop!=1) {
			a = temp[2 * j ];
			//skip check
			k = 0;//reset k
			if (!visited.empty()) {//make sure visited is not empty
				while (visited[k] != visited.back()) {//make sure not at end of vector
					b = visited[k];
					k++;//inc k
					if (atoi(a.c_str()) == atoi(b.c_str()))//check to see if we should stop
						skip = 1;
				}
				b = visited.back();
				if (atoi(a.c_str()) == atoi(b.c_str()))//check to see if we should stop
					skip = 1;
				//end skip check
			}
			if (skip == 0) {//found new value
				Q.push(temp[2 * j]);//push to queue
				visited.push_back(a);//add to visited
			}			
			if (temp[2 * j + 1] == temp.back()) {//check to see if we should stop
				stop = 1;
			}
			skip = 0;//reset skip
			j++;//inc j
		}			
		std::cout << Q.front() << std::endl;	//ouput node		
		Q.pop();		//clean from queue
		i = 0;//reset i
		stop = 0;//reset stop
	}
}
void Graph::Prim(int num)
{
	sort();//sort adjacencyList by weight instead of node index
		   //declarations
	int i = 0, j = 0, k = 0, skip = 0, v_index = 0, stop = 0, first = 0;
	std::string a, b, c,str;
	std::vector<std::string> temp;//used as temporary storage
	std::queue <std::string> Q;//queue
	std::vector<std::string> visited;//list of visited nodes
	std::cout << "Min spanning tree:" << std::endl;
	int number = num - 1;//node correction in vector
	std::stringstream out;
	out << num;
	str = out.str();
	Q.push(str);//push first node to queue
	visited.push_back(str);//add first node to visited
	temp = adjacencyList[number];//used to look at node in adjacencyList
	while (!Q.empty()) {//keep going until queue is empty
		if (first == 1) {//if first run through skip 
			c = Q.front();//looks at front of queue
			temp = adjacencyList[atoi(c.c_str())];//loads front of queue to temp
		}
		first = 1;
		j = 0;//reset j

		while (stop != 1) {
			a = temp[2 * j];
			//skip check
			k = 0;//reset k
			if (!visited.empty()) {//make sure visited is not empty
				while (visited[k] != visited.back()) {//make sure not at end of vector
					b = visited[k];
					k++;//inc k
					if (atoi(a.c_str()) == atoi(b.c_str()))//check to see if we should stop
						skip = 1;
				}
				b = visited.back();
				if (atoi(a.c_str()) == atoi(b.c_str()))//check to see if we should stop
					skip = 1;
				//end skip check
			}
			if (skip == 0) {//found new value
				Q.push(temp[2 * j]);//push to queue
				visited.push_back(a);//add to visited
			}
			if (temp[2 * j + 1] == temp.back()) {//check to see if we should stop
				stop = 1;
			}
			skip = 0;//reset skip
			j++;//inc j
		}
		std::cout << Q.front() << std::endl;	//ouput node		
		Q.pop();		//clean from queue
		i = 0;//reset i
		stop = 0;//reset stop
	}
	
}
void Graph::assignLow(int)//find articulation points
{
	//method not implemented yet
}
void Graph::SSP(int)//find sortest path
{
	//method not implemented yet
}
void Graph::sort()//sorts adjacencyList by weight
{
	char* ptr1;//used in strtof
	char* ptr2;//used in strtof
	bool swapped = true;//used for bubble sort
	int stop=0,j,k;
	std::vector<std::string> v;//temporary storage
	for (int i = 0; i < num_vert; i++) {//have to print out num_vert nodes
		v = adjacencyList[i];//
		j = 0;//reset j
		swapped = true;//set bool
		while (swapped) {//keep going while bool is ture
			swapped = false;//set bool
			j++;//inc j
			k = 0;//reset k
			stop = 0;//reset stop
			while (stop != 1) {
				if (strtof(v[2 * k + 1].c_str(), &ptr1) > strtof(v[2 * k + 3].c_str(), &ptr2)) {//compare
					swap(v[k * 2], v[2 * k+2]);//swap
					swap(v[k * 2 + 1], v[2 * k + 3]);//swap
					swapped = true;//swap happened so keep going
				}
				if (v[2 * k + 3] == v.back()) {//check to make sure we arent at end of vector
					stop = 1;
				}
				k++;//inc k
			}	
		}
		adjacencyList[i] = v; //save sorted over unsorted
	}
}
Graph::~Graph()//deconstructor
{
}