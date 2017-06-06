#ifndef STACKCALCULATOR1_H
#define STACKCALCULATOR1_H

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <algorithm>
	
using namespace std;

class StackCalculator1 {
	public:
		double operator()(const string& equation);
	private:
		int precede(char c1, char c2);
		double calc(char oper, double num1, double num2);
};
	
#endif

