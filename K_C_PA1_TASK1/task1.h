//task1.h
#ifndef BBHORSE_H_EXISTS
#define BBHORSE_H_EXISTS
class task1{
public:
	task1();
	double f(int); //log(n)
	double g(int); //n*log(n)
	int h(int); //n
	int p(int); //n^2
	int q(int); //n^3
	int w(int); //2^n
	long long d(int); //n!
	int num, i;
	void run();
	time_t start, finish;
	~task1();
};
#endif
