//qSortRecord.h
#ifndef QSORTRECORD_H_EXISTS
#define QSORTRECORD_H_EXISTS
#include <vector>
#include <string>
class qSortRecords
{
public:
	qSortRecords();
	void SortRecords(std::vector<std::vector<std::string> > *v, int low, int high, int(*compareRecords)(const std::vector<std::string> *a, const std::vector<std::string> *b));
	int selectPivotRecord(std::vector<std::vector<std::string> > *v, int low, int high, int(*compareRecords)(const std::vector<std::string> *a, const std::vector<std::string> *b));
	~qSortRecords();
};
#endif

