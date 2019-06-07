//BinaryTree.h
#ifndef BINARYTREE_H_EXISTS
#define BINARYTREE_H_EXISTS
#include "Hash.h"
#include "BinaryTreeNode.h"
class BinaryTree
{
private:
	BinaryTreeNode * root; //root of binary tree
	BinaryTreeNode * walker; //moves through tree to keep track of location
	bool flag; //check if at first instance of postOrder
public:
	BinaryTree(); //constructor
	~BinaryTree(); //destructor
	int findRoot(vector<vector<int> > tripletList, int nTriplets); //findRoot and return it
	void construct(Hash * hash, int root); //construct binary tree given root from hash
	void postOrder(); //print tree post-order traversal
	BinaryTreeNode* getRoot(); //returns root
};
#endif