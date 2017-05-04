#ifndef EXPRESS_H
#define EXPRESS_H
#include<stack>
#include<string>

using namespace std;  

class ArithmeticExpression{
	stack<char> opStack;  
	stack<double> numStack;  
	string orgExp, postExp;  
	
public:
	ArithmeticExpression(string ptrExp){
		orgExp=ptrExp;
		transExp();
	}
	void transExp() {  
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
				i --;  
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
	double calcExp() {  
		double tmp;  
		char ch = postExp[0];  
		int i = 1;  
		double a, b;  
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
};

#endif

