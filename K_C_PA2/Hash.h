//Hash.h
#ifndef HASH_H_EXISTS
#define HASH_H_EXISTS
#include "hashNode.h"
using namespace std;
class Hash
{
private:
	int hashSize; //size of hash
public:
	Hash(int hashSize); //overloaded consturctor
	~Hash(); //deconstructor
	vector<hashNode*> hashTable; //hash table
	int getHashSize(); //return private member hashSize
	int hashFunc(vector<int> triplet); //find keys hash table location
	void insert(vector<int> triplet); //insert triplet into hash table
	vector<int> search(int key); //find nodeID's location in hash Table
};
#endif