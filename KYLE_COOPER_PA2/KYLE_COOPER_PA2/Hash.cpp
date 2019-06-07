//Hash.cpp
#include "Hash.h"
#include <cstddef>
using namespace std;
Hash::Hash(int hashS) //overloaded constructor
{
	int i; //temp var for, for loop
	hashSize = hashS; //initalize hashSize
	for (i = 0; i < hashSize; i++) { //loop n times, where n is hashSize
		hashTable.push_back(new hashNode()); //create n link lists where n is hashSize
	}
}
Hash::~Hash() //deconstructor
{
	int i; //temp var for, for loop
	for (i = 0; i < hashSize; i++) { //loop n times, where n is hashSize
		delete hashTable[i];
	}
	hashTable.clear(); //zeroize
}
int Hash::getHashSize() //get private var hashSize
{
	return hashSize; //return hashSize
}
int Hash::hashFunc(vector<int> triplet) //find keys hash table location
{
	int value = triplet[0];
	value=value%hashSize;
	return value;
}
void Hash::insert(vector<int> triplet) //insert triplet into hash table
{
	int key = hashFunc(triplet); //find keys location in hash table
	hashNode* node = hashTable[key]; //pointer node at hashTable key location
	while (node->next != NULL) { //move pointer through chain until the end
		node = node->next; 
	}
	node->next = new hashNode(); //new link list node that end of chain
	node->v = triplet; //insert triplet into link list node
}
vector<int> Hash::search(int nodeID) //find nodeID's location in hash Table
{
	int i;
	hashNode* node = hashTable[nodeID%hashSize]; //find location of nodeID in hash table
	while (nodeID != node->v[0]&&node->next!=NULL) { //find nodeID in link list chain
		node = node->next;
	}
	return node->v; //return triplet for nodeID
}