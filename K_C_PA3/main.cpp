//main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "qSortRecord.h"
using namespace std;
/*FUNCTION PROTOTYPES*/
int compareRecords(const vector<string> *a, const vector<string> *b);
void mWayMerge(string, string, int m, int n);
int main(int argc, char* argv[])
{
	int j, i, n, m, nc; //counters: i,j. n = # elements per block, nc = total # records
	vector<string> record;//used for storing record data
	vector<vector<string> > record_list;//used for storing n records for sorting
	string line;//used in getting record data
	qSortRecords* Sort = new qSortRecords;
	/*START GET INPUT*/
	if (argc == 4) {//makes sure user entered 3 arguments
		ifstream textFile(argv[1]); //textFile takes first argument of execution command for file name
		if (textFile.is_open()) { //check if able to open file
			getline(textFile, line); //gets #records
			nc = atoi(line.c_str());//converts string to int
			m = atoi(argv[3]);//m-way merge
			n = nc / m;//calculate n, n= # of records per block
			ofstream auxFile(argv[2], fstream::out);//auxFile takes second argument of execution command for file name
			for (j = 0; j < m; j++) { //m blocks of records are sorted
				for (i = 0; i < n; i++) { //stores n records in a block
					getline(textFile, line, ' ');//get first key
					record.push_back(line);
					getline(textFile, line, ' ');//get second key
					record.push_back(line);
					getline(textFile, line, ' ');//get thrid key
					record.push_back(line);
					getline(textFile, line);//get record data
					record.push_back(line);
					record_list.push_back(record);//put record into block
					record.erase(record.begin(), record.end()); //prep temp for next set block of data
				}
				Sort->SortRecords(&record_list, 0, n - 1, compareRecords);//sorts block of n records
				if (auxFile.is_open()) {//writes sorted block of records to auxFile
					for (i = 0; i < n; i++) {
						record = record_list[i];
						for (int j = 0; j <= 3; j++) {
							auxFile << record[j] << " ";
						}
						auxFile << endl;
						record.erase(record.begin(), record.end()); //prep temp for next set block of data
					}
				}
				else cout << "Unable to open file";//failed to open file
				record_list.erase(record_list.begin(), record_list.end());//prep record_list for new block
				cout << "qSort: " << m << " of " << j << endl;//shows progress
			}
			auxFile.close();//close auxFile
		}
		textFile.close(); //close textFile
		mWayMerge(argv[2], "output.txt", m, n);//merge sorted blocks in aux file to a single block sorted in output file
	}
	/*CLEAN UP*/
	record.clear();
	record_list.clear();
	delete Sort;
	return 0;
}
int compareRecords(const vector<string> *a, const vector<string> *b) { //if a greater return 1, if a less return -1
	char* ptr1;
	char* ptr2;
	if (atoi(a->at(0).c_str())<atoi(b->at(0).c_str())) { //vs1[0] < vs2[0]
		return -1;
	}
	else if (atoi(a->at(0).c_str())>atoi(b->at(0).c_str())) { //vs1[0] > vs2[0]
		return 1;
	}
	else {
		if (strtof(a->at(1).c_str(), &ptr1)<strtof(b->at(1).c_str(), &ptr2)) { //vs1[1] < vs2[1]
			return -1;
		}
		else if (strtof(a->at(1).c_str(), &ptr1)>strtof(b->at(1).c_str(), &ptr2)) { //vs1[1] > vs2[1]
			return 1;
		}
		else {
			if (a->at(2).compare(b->at(2))<0) { //vs1[2] < vs2[2]
				return -1;
			}
			else if (a->at(2).compare(b->at(2)) > 0) { //vs1[2] > vs2[2]
				return 1;
			}
			else {
				return 1; //return 1 if they are the same
			}
		}
	}
}
void mWayMerge(string aux, string output, int m, int n) { //m = #blocks, n = # of elements in a block
	vector<int> index; //keeps track location inside each block
	vector<vector<string> > min_list;//list of current mins inside each block
	vector<string> current_min;//current min value
	string line;//used in getline
	int i, j, k,index_tracker; //counters: i, j, k. index_tracker tracks 
	/*INI INDEXS*/
	for (i = 0; i < m; i++) {
		index.push_back(0);
	}
	/*GET MINS*/
	for (i = 0; i < m; i++) {
		ifstream auxFile(aux.c_str());
		if (auxFile.is_open()) {
			for (j = 0; j < i*n; j++) {
				getline(auxFile, line);
			}
			getline(auxFile, line, ' ');
			current_min.push_back(line);
			getline(auxFile, line, ' ');
			current_min.push_back(line);
			getline(auxFile, line, ' ');
			current_min.push_back(line);
			getline(auxFile, line);
			current_min.push_back(line);
		}
		auxFile.close();
		min_list.push_back(current_min);
		current_min.erase(current_min.begin(), current_min.end());
	}//END IF GET MINS
	ofstream outputFile(output.c_str(), fstream::out);
	for (i = 0; i < m*n; i++) {//write m*n records to output
		for (j = 0; j < m; j++) {//check m blocks for lowest value
			if (index[j] < n) {//check index[j] < n
				if (current_min.empty()) {//set new current min if none is set
					current_min = min_list.at(j);
					index_tracker = j;
				}
				else {
					if (compareRecords(&current_min, &min_list.at(j))>0) {//compare records
						current_min = min_list.at(j);
						index_tracker = j;
					}
				}
			}//END IF index[j] < n
		} //END FOR 0 - m
		  /*WRITE TO OUTPUT*/
		if (outputFile.is_open()) {
			for (k = 0; k < 4; k++) {
				outputFile << current_min[k] << " ";
			}
			outputFile << endl;
		}
		else cout << "Unable to open file";
		current_min.erase(current_min.begin(), current_min.end());//prep for new write
		/*NEW CURRENT MIN*/
		/*old min value in min_list is outdated, so index_tracker is moved up to next
		lowest value*/
		index[index_tracker]++;
		ifstream auxFile(aux.c_str());
		if (auxFile.is_open()) {//go through auxFile and find new value
			for (k = 0; k < index_tracker*n + index[index_tracker]; k++) {
				getline(auxFile, line);
			}
			getline(auxFile, line, ' ');
			current_min.push_back(line);
			getline(auxFile, line, ' ');
			current_min.push_back(line);
			getline(auxFile, line, ' ');
			current_min.push_back(line);
			getline(auxFile, line);
			current_min.push_back(line);
		}
		auxFile.close();
		min_list.at(index_tracker) = current_min;
		current_min.erase(current_min.begin(), current_min.end());
		cout << "Merge: " << m*n << " of " << i << endl;
	} //END FOR 0 - m*n
	outputFile.close();
	/*CLEAN UP*/
	index.clear();
	min_list.clear();
	current_min.clear();
}//END mWayMerge
