//Stack.h
#ifndef STACK_H_EXISTS
#define STACK_H_EXISTS
class Stack
{
public:
	Stack();
	void push(char);
	char pop();
	bool isEmpty();
	bool isFull();
	~Stack();
private:
	int topOfStack; //keeps track of top of stack
	int * myArray;
};
#endif