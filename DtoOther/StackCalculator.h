#ifndef STACKCALCULATOR_H
#define STACKCALCULATOR_H
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

class StackCalculator {
	struct OPERATOR {
		char oper;			//运算符
		int priority_left;	//先出现的运算符的优先级
		int priority_right;	//后出现的运算符的优先级
	};
	
	int operator_loc(vector<OPERATOR>& ov, char c) {
		int i = 0;
		for (vector<OPERATOR>::const_iterator it = ov.begin(); it != ov.end(); ++it) {
			if (it->oper == c) break;
			++i;
		}
		return i;
	}
	
	double calc(char oper, double num1, double num2) {
		double num = 0;
		switch (oper) {
		case '+': num = num1 + num2; break;
		case '-': num = num1 - num2; break;
		case '*': num = num1 * num2; break;
		case '/': num = num1 / num2; break;
		}
		return num;
	}
	
public:
	double operator()(string equation) {
		//计算式包含浮点数（0~9、.）、运算符（+、-、*、/、(、)），以“=”结尾
		//为计算式中包含的数字和运算符分别建栈
		//算符栈栈顶的算符与新读入的算符进行算符优先级比较，如果新读入的算符优先级高就压入栈，
		//如果新读入外的算符优先级低就利用栈内的算符进行计算，并将计算结果压入数字栈
		vector<OPERATOR> operator_vector = { { '+', 2, 1 },{ '-', 2, 1 },{ '*', 4, 3 },{ '/', 4, 3 },{ '(', 0, 5 },{ ')', 4, 0 },{ '=', 0, 0 } };
		stack<char> operator_stack;	//算符栈
		operator_stack.push('=');	//算符栈中预先压入'='，便于运算符比较操作，计算式遇到最后的'='时，计算结束
		stack<double> operand_stack;//数字栈
		
		string num;
		for (char c : equation) {
			if (c >= '0' && c <= '9' || c == '.') { //数字
				num += c;
			}
			else {
				if (num != "") { //构成一个浮点数
					operand_stack.push(atof(num.c_str()));
					num = "";
				}
				if (operator_loc(operator_vector, c) != operator_vector.size()) { //算符
					while (true) {
						char ct = operator_stack.top();
						int i = operator_loc(operator_vector, ct);	//算符栈栈顶元素在操作符数组中的位置
						int j = operator_loc(operator_vector, c);	//刚读入的操作符在操作符数组中的位置
						
						if (operator_vector[i].priority_left < operator_vector[j].priority_right) {
							//新读入的算符优先级高，算符入栈
							operator_stack.push(c);
							break;
						}
						else if (operator_vector[i].priority_left > operator_vector[j].priority_right) {
							//新读入的算符优先级低，根据栈顶算符计算
							double num2 = operand_stack.top();
							operand_stack.pop();
							double num1 = operand_stack.top();
							operand_stack.pop();
							double num = calc(ct, num1, num2);
							operand_stack.push(num);
							operator_stack.pop();
						}
						else if (operator_vector[i].priority_left == operator_vector[j].priority_right) {
							//如果新读入的算符为结束符'='，则对应的算符栈栈顶为预先压入的结束符'='
							//如果新读入的算符为')'，则对应的算符栈栈顶为'('
							operator_stack.pop();
							break;
						}
					}
				}
			}
		}
		
		return operand_stack.top();
	}
};

#endif

