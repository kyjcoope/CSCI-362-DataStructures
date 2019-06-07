//task1.cpp
#include <iostream>
#include <fstream>
#include <time.h>
#include <cmath>
#include "task1.h"
using namespace std;
task1::task1()
{
}
void task1::run() {
	cout << "Please enter a positive integer<< ";
	cin >> num; //user input
	ofstream outputFile; 
	outputFile.open("results.txt"); //output file
	start = clock(); //start time
	for (i = 1; i < num; i++) {
		outputFile << f(i);
		outputFile << ", " << g(i);
		outputFile << ", " << h(i);
		outputFile << ", " << p(i);
		outputFile << ", " << q(i);
		outputFile << ", " << w(i);
		outputFile << ", " << d(i) << endl;
	}
	finish = clock(); //time finish
	finish = finish - start; //calulate total time
	cout << "execution time: " << float(finish) / CLOCKS_PER_SEC << "seconds" << endl << endl; //output total time
	outputFile.close();
}
double task1::f(int num) { //log(n)
	return log(num);
}
double task1::g(int num) { //n*log(n)
	return num*log(num);
}
int task1::h(int num) { //n
	return num;
}
int task1::p(int num) { //n^2
	return num*num;
}
int task1::q(int num) { //n^3
	return num*num*num;
}
int task1::w(int num) { //2^n
	return 2 ^ num;
}
long long task1::d(int num) { //n!
	if (num == 0)
		return 1;
	else
		return num*d(num - 1);
}
task1::~task1()
{
}
