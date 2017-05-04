#include "Calculator.h"
#include <iostream>  
#include <stack>  
using namespace std;

double toNum(char*s, int &k)  
{  
	int flag = 0;  
	double x = 0.0, y = 0.1;  
	while (s[k] >= '0'&&s[k] <= '9' || s[k] == '.')  
	{  
		if (s[k] >= '0'&&s[k] <= '9')  
		{  
			if (flag == 0)  
				x = x * 10 + s[k] - '0';  
			else  
			{  
				x = x + y*(s[k] - '0');  
				y = y*0.1;  
			}  
		}  
		else  
		{  
			flag = 1;  
		}  
		k = k + 1;  
	}  
	return x;  
}  

int priority(char c)  
{  
	int k;  
	switch (c)  
	{  
	case '*':k = 2; break;  
	case '/':k = 2; break;  
	case '+':k = 1; break;  
	case '-':k = 1; break;  
	case '(':k = 0; break;  
	case ')':k = 0; break;  
	default:k = -1; break;  
	}  
	return k;  
}  

void Calculator()  
{  
	stack<double> sv;  
	stack<char> sp;  
	char c;  
	int k = 0, flag = 1;  
	double x, y;  
	sp.push('\0');  
	char *s = new char[100];  
	cout << "ÇëÊäÈëËãÊ½£º" << endl;  
	cin >> s;  
	c = s[k];  
	while (flag)  
	{  
		if (c >= '0'&&c <= '9' || c == '.')  
		{  
			sv.push(toNum(s, k));  
		}  
		else if (c == '\0'&& sp.top() == '\0')  
		{  
			flag = 0;  
		}  
		else if (c == '(' || (priority(c) > priority(sp.top())))  
		{  
			sp.push(c);  
			k++;  
		}  
		else if (c == ')'&& sp.top() == '(')  
		{  
			sp.pop();  
			k++;  
		}  
		else if (priority(c) <= priority(sp.top()))  
		{  
			x = sv.top();  
			sv.pop();  
			y = sv.top();  
			sv.pop();  
			c = sp.top();  
			sp.pop();  
			switch (c)  
			{  
			case '+':y = x + y; break;  
			case '-':y = y - x; break;  
			case '*':y = x*y; break;  
			case '/':y = y / x; break;  
			}  
			sv.push(y);  
		}  
		c = s[k];  
	}  
	cout << sv.top() << endl;   
}  
void testCalculator(){
	Calculator();
}
