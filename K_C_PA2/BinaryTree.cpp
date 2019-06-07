//BinaryTree.cpp
#include "BinaryTree.h"
#include <iostream>
BinaryTree::BinaryTree() //constructor
{
	root = NULL; //set root to NULL
	flag = true;
}
BinaryTree::~BinaryTree() //desturctor
{
	/*deleting root will cause tree to be deleted in recursive manner,
	since root is a BinaryTreeNode*, it will call the BinaryTreeNode
	deconstructor. This will delete roots right and left Child nodes,
	which	will then causes their deconstructors to becalled deleting
	their children. This will contine until all child nodes are deleted. 
	*/
	delete root;
	root = NULL;
	walker = NULL;
}
int BinaryTree::findRoot(vector<vector<int> > tripletList, int nTriplets) //find nodeID of root
{
	vector<int> x,y; //nodeID is in first triplet in vector
	int i,j,root;
	bool flag = false; //used to check if not root
	for (i = 0; i < nTriplets; i++) {
		flag = false; //set flag
		x = tripletList[i]; //current value to check
		for (j = 0; j < nTriplets; j++) {
			y = tripletList[j]; //current value to check against
			if (x[0] == y[1] || x[0] == y[2]) {
				flag = true;
				break; //current value checking against is not root
			}
		}
		if (flag == false) {
			return x[0]; //return root
		}
	}
}
void BinaryTree::construct(Hash * hash, int root) //builds binary tree
{
	if (BinaryTree::root == NULL) { //if root is NULL fill it out first
		BinaryTreeNode* temp = new BinaryTreeNode(root);
		BinaryTree::root = temp;
		BinaryTree::root->NodeID = root; //give root its nodeID
		vector<int> v = hash->search(root); //find nodeID's for next nodes
		if (v[1] != -1) { //if nodeID would be -1 leave blank
			BinaryTree::root->leftChild = new BinaryTreeNode(v[1]); //create new node for left child and set its nodeID
			walker = BinaryTree::root->leftChild;
			construct(hash, v[1]); //continue building tree, send current nodes nodeID for future lookups
		}
		if (v[2] != -1) { //if nodeID would be -1 leave blank
			BinaryTree::root->rightChild = new BinaryTreeNode(v[2]); //create new node for right child and set its nodeID
			walker = BinaryTree::root->rightChild;
			construct(hash, v[2]); //continue building tree, send current nodes nodeID for future lookups
		}
		//temp = NULL;
	}
	else if (walker != NULL) { //if root is not NULL
		BinaryTreeNode* current = walker; //temp node
		vector<int> v = hash->search(root); //find nodeID's for next nodes
		if (v[1] != -1) { //if nodeID would be -1 leave blank
			current->leftChild = new BinaryTreeNode(v[1]); //create new node for left child and set its nodeID
			walker = current->leftChild;
			construct(hash, v[1]); //continue building tree, send current nodes nodeID for future lookups
		}
		if (v[2] != -1) { //if nodeID would be -1 leave blank
			current->rightChild = new BinaryTreeNode(v[2]); //create new node for right child and set its nodeID
			walker = current->rightChild;
			construct(hash, v[2]); //continue building tree, send current nodes nodeID for future lookups
		}
		//current = NULL;
	}
	else {
		return;
	}
}
void BinaryTree::postOrder()
{
	BinaryTreeNode* temp; //used to reset walkers place
	if(flag){ //used to check if at first instance of postOrder or not
		flag = false; //set flag to false
		temp = root;
		walker = temp->leftChild; //move walker to leftChild
		postOrder(); //do post order on left child
		walker = temp->rightChild; //move walker to rightChild
		postOrder(); //do post order on right child
		walker = temp; //reset walker
		flag = true; //reset flag for future use of postOrder()
		temp = NULL;
	}
	else { //if not at first instance of postOrder()
		if (walker==NULL) { //check if node is NULL
			return; //return if node is NULL, at bottom of tree
		}
		temp = walker;
		walker = temp->leftChild; //move walker to leftChild
		postOrder(); //do post order on left child
		walker = temp->rightChild; //move walker to rightChild
		postOrder(); //do post order on right child
		walker = temp; //reset walker
	}
	cout << walker->NodeID << endl; //print current nodes nodeID
}
BinaryTreeNode * BinaryTree::getRoot() //get private member varible root
{
	return root; //return root
}
