graph: Graph.o main.o
	g++ Graph.o main.o -o graph
Graph.o: Graph.cpp Graph.h
	g++ Graph.cpp -c
main.o: main.cpp Graph.h
	g++ main.cpp -c
clean:
	rm -f *.o
	rm graph
run:
	./graph