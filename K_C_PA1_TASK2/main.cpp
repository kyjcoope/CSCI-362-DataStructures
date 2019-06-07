// main.cpp
#include <iostream>
#include <string>
#include "Evaluator.h"
#include "Stack.h"
using namespace std;
int main()
{
	Evaluator* begin = new Evaluator; //create evaluator object
	begin->eval();
	delete begin;
	return 0;
}

