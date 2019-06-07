pa1t1: task1.o main.o
	g++ task1.o main.o -o pa1t1
task1.o: task1.cpp task1.h
	g++ task1.cpp -c
main.o: main.cpp task1.h
	g++ main.cpp -c
clean:
	rm -f *.o
	rm pa1t1
run:
	./pa1t1