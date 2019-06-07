//Stack.cpp
#include "Stack.h"
#include <vector>
using namespace std;
Stack::Stack()
{
	myArray = new int[10]; //allocate memory for stack
	for (int i = 0; i < 10; i++) myArray[i] = 0; //clear stack
	topOfStack = -1;
}
Stack::~Stack()
{
	delete [] myArray; //clear memory
}
void Stack::push(char c) { //push value ontop of stack
	topOfStack++;
	myArray[topOfStack] = c;

}
char Stack::pop() { //pop top value off of stack
	char c = myArray[topOfStack];
	myArray[topOfStack] = 0;
	topOfStack--;
	return c;
}
bool Stack::isEmpty() { //check if stack is empty
	if (topOfStack == -1)
		return true;
	else
		return false;
}
bool Stack::isFull() { //check if stack is full
	if (topOfStack >= 9)
		return true;
	else
		return false;
}