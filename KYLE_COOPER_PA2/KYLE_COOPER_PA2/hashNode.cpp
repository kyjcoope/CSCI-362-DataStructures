//hashNode.cpp
#include "hashNode.h"
#include <iostream>
using namespace std;
hashNode::hashNode() //constructor
{
	next = NULL; //set next link to NULL
}


hashNode::~hashNode() //deconstructor
{
	delete next;
	next = NULL;
}
