#ifndef STACKCALCULATOR2_H
#define STACKCALCULATOR2_H

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct S {
	enum { OPER, NUM } tag;
	union {
		char c;
		double d;
	};
	S(char op) : tag(OPER), c(op) {}
	S(double num) : tag(NUM), d(num) {}
};

class StackCalculator2 {
public:
	double operator()(const string& exp);
private:
	vector<S> vs;
	bool precede(char c1, char c2); //比较两个运算符的优先级
	double calc(char op, double d1, double d2); //四则运算
	void transform(const string& exp, vector<S>& vs); //将表达式转换成后缀表示式
};
#endif

