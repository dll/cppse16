#include "PriorityCalcultor.h"
#include <iostream>  
#include <stack>  
#include <cstdlib>  
using namespace std;

double PriorityCalcultor::toNum(char*s, int &k){  
	int flag = 0;  
	double x = 0.0, y = 0.1;  
	while (s[k] >= '0'&&s[k] <= '9' || s[k] == '.')	{  
		
	}  
	return x;  
}  

int PriorityCalcultor::priority(char c){  
	int k;  
	switch (c){  
		case '*':k = 2; break;  
		case '/':k = 2; break;  
		case '+':k = 1; break;  
		case '-':k = 1; break;  
		case '(':k = 0; break;  
		case ')':k = 0; break;  
		default:k = -1; break;//=结束  
	}  
	return k;  
}  

void PriorityCalcultor::Calculator()  
{  
	stack<double> sv;  
	stack<char> sp;  
	char c;  
	int k = 0, flag = 1;  
	double x, y;  
	sp.push('=');//结束标志
	char *s = new char[100];  
	cout << "请输入算式：" << endl;  
	cin >> s;  
	c = s[k];  
	while (flag){  
		
	}  
	cout << sv.top() << endl;   
	delete s;
}  
