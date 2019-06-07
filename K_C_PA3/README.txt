/*HOW TO COMPILE*/
To compile task1 make sure to move Makefile and all source files into the same directory
Type>> make

To run the files after they are compiled
Type>> ./mySortingSys <input file> <aux file> <value of m>

<input file>: must be a .txt file, and is the file you want sorted, example: input.txt
<aux file>: must be a .txt file, file will be created by program, example: aux.txt
<value of m>: will be the number of blocks to be sorted and number of merges that will be done,
must be an EVEN integer value. that is >0 and less then total number of records divided by 2

A file called output.txt will be stored in the same directory as program is run. output.txt
will be a sorted version of the input file.

To remove all .o files
Type>> make clean

/*FUNCTIONS AND CLASS DESTRIPTIONS*/
-int main(int argc, char* argv[])
    takes arguments from user for input file, aux file, and m blocks. After declarations 
int main, will make sure 3 arguments were entered by the user. After this it will start
getting blocks of records from the input file. This is done by opening an ifstream
that takes the first argument the user enters as the name of the input file. nc takes the first
line of input file as the total number of records to go through. m takes the 3rd argument
given by the user as the number of blocks. After this a for loop is run that grabs m blocks of records.
Inside this for loop, another for loop is run that grabs n records to be stored inside vector record_list.
record_list stores only a single block of records at a time, and is then cleared before getting another block.
After a block is grabbed the block is sorted, then writted to aux file. After all records in input file, have
been saved in sorted blocks to aux file, the aux file(which is given by the second argument from the user) is
passed to the function mWayMerge, which merges all the blocks in the aux file to a single sorted block inside
the output file.

mWayMerge and compareRecords function, both belong to int main.

-int compareRecords(const vector<string> *a, const vector<string> *b)
    compareRecords takes two vector<string> addresses, which contain the two records being
compared. compareRecords will return a 1 if *a is > b*, and -1 if *a is < b*.
The primary keys of both are compared first, and since they are stored as strings
inside the vector, I use atoi to convert them into int's for compare. If the primary keys
end up being the same, the secondary keys are then compared. Since they are also stored as
strings, they have to be converted to floats with strof, for the compare. If the secondary
keys also end up being the same, the tertiary keys are compared, since the tertiary keys
are already strings we can just do a string compare of both to find out what order they need
to be in. If the tertiary keys are the same, 1 is just returned since *a is before *b in the file
no matter what.

-void mWayMerge(string aux, string output, int m, int n)
    mWayMerge takes 4 arguments two strings aux and output, which will be used as file names,
and two int's m and n. m = #blocks, n = # of records per block. A vector of side m vector index is 
a vector of int's of size m is used to keep track of which value for each block is the current min,
this is used as an off set so old values of min are skipped. Another vector of side m vector<string> min_list keeps
a list of current min of each block, this prevents having to do multiple searches of the aux file.
All of vector index is initialized to 0, since the first value in all the blocks will be the lowest value.
min_list is then initialized with all the first values of each block since they all have the lowest value.

A for loop is run from 0 to n*m, n*m = the total number of records. Inside this for loop another for loop is run,
which finds the lowest value record in min_list. index_tracker gets the value of j of the lowest value record.This
record is then save to the output file. Now that the current_min of block[index_tracker] has been placed into the
output file, the index[index_tracker] is moved up one and the new record that at that location is placed into min_list,
as the new min for that block. This process is repeated until m*n records have been placed into the output file.

Class qSortRecords
    The only reason I do not include qSortRecords in int main is because compareRecords needs to be passed by
referance. Assinment didnt specify that everything must be done in classes, so most things are done in the main.
qSortRecords has two functions SortRecords and selectPivotRecord.

-void qSortRecords::SortRecords(std::vector<std::vector<std::string> >* v, int low, int high, int(*compareRecords)(const std::vector<std::string>*a, const std::vector<std::string>*b)
    Takes 4 arguments, the address of the current block being sorted *v, two ints, low and high(these will be the range of sort), and a reference to compareRecords. Since qSortRecords is a recursive function we first make sure the next sorts we are about to do, will be
valid by making sure low is not equal to or higher then high. After this a pivot is selected, and all numbers lower then the 
pivot are placed to the left/below it, and all values higher than pivot are placed to the right/above it. After this two sorts
are done, one on the values lefts of the pivot(range will be from low to pivot -1, since pivot is in its proper spot its not
included), and one on the values right of the pivot(range: from pivot+1 to high).  

-void qSortRecords::selectPivotRecord(std::vector<std::vector<std::string> >* v, int low, int high, int(*compareRecords)(const std::vector<std::string>*a, const std::vector<std::string>*b)
    A walker is used to move through values from low to high. record v->at(high) is used as the pivot record, all records
less than record v->at(high), are moved to the left of the walker. This is done by checking comparing the record at i 
location with v->at(high), if it is lower than v->at(high), the record at i is swap with the one at walker, and walker
is moved up one. After all this is done the record at walker is swapped with the record v->at(high). Is places the pivot
in its sorted located and preps the values lower and higher than pivot for the next sorts. After all this the function returns
the location of the pivot, if walker==low, nothing was lower than v->at(high), so we return high + 1, so the current selection
of records is checked again with a new pivot. if walker!=lower, we just return walker which is location the of pivot.






















