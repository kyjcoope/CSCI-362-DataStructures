//hashNode.h
#ifndef HASHNODE_H_EXISTS
#define HASHNODE_H_EXISTS
#include <vector>
using namespace std;
class hashNode
{
public:
	hashNode* next; //next node in link list
	vector<int> v; //link list data
	hashNode(); //constructor
	~hashNode(); //deconstructor
};
#endif