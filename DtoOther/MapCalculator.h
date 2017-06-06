#ifndef MAPCALCULATOR_H
#define MAPCALCULATOR_H
#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<cmath>

using namespace std;

class MapCalculator{
	multimap<int, char> mapping;
	stack<char> exps;
	stack<char> oper;
	
public:
	MapCalculator();
	void transform(string expStr);
	void calculate();
	void printExp();
	double calculate(char op,double d1, double d2);
};
#endif
