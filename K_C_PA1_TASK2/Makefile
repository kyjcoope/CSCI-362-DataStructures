pa1t2: Evaluator.o Stack.o main.o
	g++ Evaluator.o Stack.o main.o -o pa1t2
Evaluator.o: Evaluator.cpp Evaluator.h
	g++ Evaluator.cpp -c
Stack.o: Stack.cpp Stack.h
	g++ Stack.cpp -c
main.o: main.cpp Evaluator.h Stack.h
	g++ main.cpp -c
clean:
	rm -f *.o
	rm pa1t2
run:
	./pa1t2