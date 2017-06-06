#include "DeStackExpression.h"

//中缀表达式转成后缀表达式
//3+(12/(2*2+1))-->3 12 2 2 *1 +/+
void DeStackExpression::OrgExpTranslatePostExp() {  
	string::iterator iter = orgExp.begin();
	while(iter!=orgExp.end()) {  
		switch(*iter) {  
		case '(':  
			opStack.push(*iter);  
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
			opStack.push(*iter);
			break;  
		case '*':  
		case '/':  
			while(!opStack.empty() && opStack.top() != '('  
				  && (opStack.top() == '*' || opStack.top() == '/') ) {  
				postExp.push_back(opStack.top()); 
				opStack.pop();
			}  
			opStack.push(*iter);  
			break;  
		default: 
			while(*iter >= '0' && *iter <= '9'||*iter == '.') {  
				postExp.push_back(*iter);  
				++iter;
			}  
			--iter;  
			postExp.push_back(' '); 
		}  
		++iter;
	}  
	while(!opStack.empty()) {  
		postExp.push_back(opStack.top());
		opStack.pop();  
	}
}  

//计算后缀表达式
double DeStackExpression::CalcPostExp() {  
	
	string::iterator iter = postExp.begin(); 
	double a, b, x, y, z;  
	bool flag;

	while(iter!=postExp.end()) { 
		if(*iter >= '0' && *iter <= '9'||*iter == '.') {  
			flag=true; x = 0.0; y = 0.1;
			while(*iter >= '0' && *iter <= '9'||*iter == '.') {  
				if(*iter >= '0' && *iter <= '9'){
					if(flag){
						x = x * 10 + *iter - '0';//整数部分  
					}
					else{//小数部分
						x = x + y*(*iter - '0');  
						y = y*0.1;  
					}
				}
				else 
					flag=false;
				
				*iter = *(++iter);
			}  
			numStack.push(x);  
		}  
		else {  
			b = numStack.top(), numStack.pop();  
			a = numStack.top(), numStack.pop();  
			switch(*iter){  
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
		*iter = *(++iter);
	}  
	return numStack.top();  
} 
