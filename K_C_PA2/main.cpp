//main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"
#include "BinaryTree.h"
using namespace std;
int main(int argc, char* argv[])
{	
	int i,value,hashSize,nTriplets; //integer declaration
	vector<int> triplet; //triplet vector
	vector<vector<int> > triplets; //triplets vector
	string line; //used for retreving file information
	/*START GET TRIPLETS*/
	if (argc == 2) {
		ifstream textFile(argv[1]); //textFile takes first argument of execution command for file name
		if (textFile.is_open()) { //fills vector<vector<int>> triplets
			getline(textFile, line, ' '); //gets nTriplets
			nTriplets = atoi(line.c_str());
			getline(textFile, line); //gets hashSize
			hashSize = atoi(line.c_str());
			while (!textFile.eof()) { //gets all triplets, until end of file
				for (i = 0; i <= 1; i++) { //gets first two numbers of triplet with ' ' delim
					getline(textFile, line, ' ');
					value = atoi(line.c_str());
					triplet.push_back(value);
				}
				getline(textFile, line); //gets last number of triplet with /n delim
				value = atoi(line.c_str());
				triplet.push_back(value);
				triplets.push_back(triplet); //push triplet to triplets
				triplet.erase(triplet.begin(), triplet.end()); //prep triplet for next set of triplet
			}
		}
		triplets.pop_back(); //removes the last element of the vector cause it will be empty
		textFile.close(); //close textFile
	}
	else {
		cout << "Missing argument" << endl;
		system("pause");
		return 0;
	}
	/*END GET TRIPLETS*/
	Hash* hash = new Hash(hashSize); //create hash
	for (i = 0; i < nTriplets; i++) { //insert triplets into hashTable
		hash->insert(triplets[i]);
	}
	BinaryTree* binaryTree = new BinaryTree(); //create new binary tree
	int rootID = binaryTree->findRoot(triplets, nTriplets); //find nodeID of tree root
	binaryTree->construct(hash, rootID); //fill in binary tree
	binaryTree->postOrder(); //output postOrder of binary tree
	/*CLEAN UP*/
	delete binaryTree;
	binaryTree = NULL;
	delete hash;
	hash = NULL;
	triplet.clear();
	triplets.clear();
	/*END CLEAN UP*/
	return 0;
}
