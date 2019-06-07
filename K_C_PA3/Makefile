mySortingSys: qSortRecord.o main.o
	g++ qSortRecord.o main.o -o mySortingSys
qSortRecord.o: qSortRecord.cpp qSortRecord.h
	g++ qSortRecord.cpp -c
main.o: main.cpp qSortRecord.h
	g++ main.cpp -c
clean:
	rm -f *.o
	rm mySortingSys
run:
	./mySortingSys