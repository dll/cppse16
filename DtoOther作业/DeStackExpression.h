#ifndef EXPRESS_H
#define EXPRESS_H

#include<iostream>
#include<stack>
#include<string>
#include<cstdio>

using namespace std; 
class DeStackExpression{
	stack<char> opStack;  
	stack<double> numStack;  
	string orgExp;//初始表达式
	string postExp;//后缀表达式 	
public:
	DeStackExpression(string ptrExp){
		orgExp=ptrExp;
		OrgExpTranslatePostExp();
	}
	//中缀表达式转成后缀表达式
	//3+(12/(2*2+1))-->3 12 2 2 *1 +/+
	void OrgExpTranslatePostExp();
	//计算后缀表达式
	double CalcPostExp();
	//获取后缀表达式字符串
	string getPostExp();
};

#endif

