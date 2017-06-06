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
		int i = 1, j = 0;  
		ch = orgExp[0];  
		while(ch != 0) {  
			switch(ch) {  
				case '(':  
					opStack.push(ch);  
					break;  
				case ')':  
					while(opStack.top() != '(') {  
						postExp[j++] = opStack.top();  
						opStack.pop();
					}  
					opStack.pop();  
					break;  
				case '+':  
				case '-':  
					while(!opStack.empty() && opStack.top() != '(') {  
						postExp[j++] = opStack.top(); 
						opStack.pop();  
					}  
					opStack.push(ch);
					break;  
				case '*':  
				case '/':  
					while(!opStack.empty() && opStack.top() != '('  
						  && (opStack.top() == '*' || opStack.top() == '/') ) {  
						postExp[j++] = opStack.top();
						opStack.pop();
					}  
					opStack.push(ch);  
					break;  
				default: 
					while(ch >= '0' && ch <= '9') {  
						postExp[j++] = ch;  
						ch = orgExp[i++];  
					}  
					i--;  
					postExp[j++] = ' '; 
			}  
			ch = orgExp[i++];
		}  
		while(!opStack.empty()) {  
			postExp[j++] = opStack.top(); 
			opStack.pop();  
		}  
		postExp[j] = 0; 
	}  

	//计算后缀表达式
	double CalcPostExp() {  
		double tmp;  
		char ch = postExp[0];  
		int i = 0;  
		double a, b;  
		cout<<"中缀表达式： "<<orgExp<<endl;
		cout<<"后缀表达式： "<<getPostExp()<<endl;
		i=1;
		while(ch != 0) { 
			if(ch >= '0' && ch <= '9') {  
				tmp = 0;  
				while(ch >= '0' && ch <= '9') {  
					tmp = 10 * tmp + ch - '0';  
					ch = postExp[i++];
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
			ch = postExp[i++];
		}  
		return numStack.top();  
	} 
	//获取后缀表达式字符串
	string getPostExp(){
		int i=0,j=0;
		char tmp[100]="\0";
		while(postExp[i]!=0){
			tmp[j++]=postExp[i];
			if(postExp[i]=='+'||postExp[i]=='-'\
			   ||postExp[i]=='*'||postExp[i]=='/')
				tmp[j++]=' ';
			i++;
		}
		tmp[j]='\0';
		return tmp;
	}
};

#endif

