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
	void OrgExpTranslatePostExp() {  
		char ch;
		string::iterator iter = orgExp.begin();
		ch=*iter;
		while(iter!=orgExp.end()) {  
			switch(ch) {  
				case '(':  
					opStack.push(ch);  
					break;  
				case ')':  
					while(opStack.top() != '(') {  
						postExp.push_back(opStack.top());  
						opStack.pop();
					}  
					opStack.pop();  
					break;  
				case '+':  
				case '-':  
					while(!opStack.empty() && opStack.top() != '(') {  
						postExp.push_back(opStack.top()); 
						opStack.pop();  
					}  
					opStack.push(ch);
					break;  
				case '*':  
				case '/':  
					while(!opStack.empty() && opStack.top() != '('  
						  && (opStack.top() == '*' || opStack.top() == '/') ) {  
						postExp.push_back(opStack.top()); 
						opStack.pop();
					}  
					opStack.push(ch);  
					break;  
				default: 
					while(ch >= '0' && ch <= '9') {  
						postExp.push_back(ch);  
						ch = *(++iter);
					}  
					--iter;  
					postExp.push_back(' '); 
			}  
			ch = *(++iter);
		}  
		while(!opStack.empty()) {  
			postExp.push_back(opStack.top());
			opStack.pop();  
		} 
	}  

	//计算后缀表达式
	double CalcPostExp() {  
		double tmp;  
		string::iterator iter = postExp.begin(); 
		char ch=*iter;
		double a, b;  
		cout<<"中缀表达式： "<<orgExp<<endl;
		cout<<"后缀表达式： "<<getPostExp()<<endl;
		while(iter!=postExp.end()) { 
			if(ch >= '0' && ch <= '9') {  
				tmp = 0;  
				while(ch >= '0' && ch <= '9') {  
					tmp = 10 * tmp + ch - '0';  
					ch = *(++iter);
				}  
				numStack.push(tmp);  
			}  
			else {  
				b = numStack.top(), numStack.pop();  
				a = numStack.top(), numStack.pop();  
				switch(ch){  
					case '+':  
						numStack.push(a + b);  
						break;  
					case '-':  
						numStack.push(a - b);  
						break;  
					case '*':  
						numStack.push(a * b);  
						break;  
					case '/':  
						numStack.push(a / b);  
						break;  
					default:  
						break;  
				}  
			}  
			ch = *(++iter);
		}  
		return numStack.top();  
	} 
	//获取后缀表达式字符串
	string getPostExp(){
		return postExp;
	}
};

#endif

