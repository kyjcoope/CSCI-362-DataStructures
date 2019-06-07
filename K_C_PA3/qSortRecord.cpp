//qSortRecord.cpp
#include "qSortRecord.h"
qSortRecords::qSortRecords()
{
	/*qSortRecord only contains functions no varibles to initialize*/
	/*The reason I made qSortRecord a seperate class and not part
	of main.cpp is to prove that compareRecords function is
	getting passed by referance to qSortRecords*/
}

void qSortRecords::SortRecords(std::vector<std::vector<std::string> >* v, int low, int high, int(*compareRecords)(const std::vector<std::string>*a, const std::vector<std::string>*b))
{
	if (low >= high) {//returns if not a valid sort
		return;
	}
	int pivot = selectPivotRecord(v, low, high, compareRecords);//selects pivot for next sorts
	SortRecords(v, low, pivot - 1, compareRecords);//sorts low part of current sort
	SortRecords(v, pivot + 1, high, compareRecords);//sorts high part of current sort
}
int qSortRecords::selectPivotRecord(std::vector<std::vector<std::string> >* v, int low, int high, int(*compareRecords)(const std::vector<std::string>*a, const std::vector<std::string>*b))
{
	int walker = low;//used for moving through values, also will be pivot location
	for (int i = low; i <= high; i++) {//move through all values
		if (compareRecords(&v->at(i), &v->at(high))<0) { //compares records, if record *a < record *b swap
			v->at(i).swap(v->at(walker));
			walker++;//move to next value
		}
	}
	v->at(high).swap(v->at(walker));//v->at(high) is pivot value, so we move it to pivot location before leaving
	if (walker == low) {//nothing was lower than v->at(high) we check current section of records again with the new pivot 
		return high + 1;//+1 since -1 will be subtracted in qSortRecords
	}
	else return walker;//location of pivot
}
qSortRecords::~qSortRecords()
{
	/*qSortRecord only contains functions, no varibles to delete*/
}
