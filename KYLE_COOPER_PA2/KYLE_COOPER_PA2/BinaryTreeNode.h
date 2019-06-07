//BinaryTreeNode.h
#ifndef BINARYTREENODE_H_EXISTS
#define BINARYTREENODE_H_EXISTS
class BinaryTreeNode
{
public:
	int NodeID; //node ID
	BinaryTreeNode * leftChild; //left Child
	BinaryTreeNode * rightChild; //right Child
	BinaryTreeNode(int nodeID); //overloaded constructor
	~BinaryTreeNode(); //destructor
};
#endif