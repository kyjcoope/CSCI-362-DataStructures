//BinaryTreeNode.cpp
#include <iostream>
#include "BinaryTreeNode.h"
BinaryTreeNode::BinaryTreeNode(int nodeID) //overloaded constructor
{
	NodeID = nodeID; //initalize nodeID
	rightChild = NULL; //set right child to NULL
	leftChild = NULL; //set left child to NULL
}
BinaryTreeNode::~BinaryTreeNode() //deconstructor
{
	if (leftChild != NULL) {
		delete leftChild;
		leftChild = NULL;
	}
	if (rightChild != NULL) {
		delete rightChild;
		rightChild = NULL;
	}
}