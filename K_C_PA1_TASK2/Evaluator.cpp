// Evaluator.cpp
#include "Evaluator.h"
#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;
Evaluator::Evaluator() 
{
	evalStack = new char[100]; //allocate memory for evalStack
	for (int i = 0; i < 100; i++) evalStack[i] = 0; //zeroize evalStack
}
Evaluator::~Evaluator() 
{
	delete [] evalStack; //clear memory
}
void Evaluator::eval() {
	Stack* stackObject = new Stack(); //Create Stack
	int i,num1,num2,sum=0,operators=0,oprands=0;
	cout << "Please enter a valid postfix expression: "; 
	cin >> evalStack; //input user info into evalStack
	for (i = 0; i < 100; i++) { //move through evalStack element by element
		if (evalStack[i] == '-'|| evalStack[i] == '+'|| evalStack[i] == '/'|| evalStack[i] == '*') { //check if element i of evalStack is an operator
			if (evalStack[i] == '-') { //check if element i of evalStack is an operator
				num1 = stackObject->pop();
				num2 = stackObject->pop();
				sum = num1 - num2;
				stackObject->push(sum);
			}
			else if (evalStack[i] == '+') { //check if element i of evalStack is an operator
				num1 = stackObject->pop();
				num2 = stackObject->pop();
				sum = num1 + num2;
				stackObject->push(sum);
			}
			else if (evalStack[i] == '/') { //check if element i of evalStack is an operator
				num1 = stackObject->pop();
				num2 = stackObject->pop();
				sum = (num1 / num2);
				stackObject->push(sum);
			}
			else if (evalStack[i] == '*') { //check if element i of evalStack is an operator
				num1 = stackObject->pop();
				num2 = stackObject->pop();
				sum = (num1)* (num2);
				stackObject->push(sum);
			}
			operators++;
		}
		else if(evalStack[i]>=48&& evalStack[i] <= 57){ //places element of evalStack onto stack if a number between 0-9
			stackObject->push(evalStack[i]-48); //-48 to correct for ascii value
			oprands++;
		}
	}
	sum = stackObject->pop(); //pop value off if postfix expression was valid nothing should be on the stack now
	if (operators>=oprands) { //if stack is not empty or i<9 print error
		cout << "You have too many operators in your expression." << endl<<endl;
	}
	else if (oprands != operators + 1) {
		cout << "You have too few operators in your expression." << endl << endl;
	}
	else
		cout <<"Solution: "<< sum << endl << endl; //output solution
}
