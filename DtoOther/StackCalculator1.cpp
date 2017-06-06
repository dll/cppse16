#include "StackCalculator1.h"

double StackCalculator1::operator()(const string& equation) {
	//计算式包含浮点数（0~9、.）、运算符（+、-、*、/、(、)），以“=”结尾
	//为计算式中包含的数字和运算符分别建栈
	//算符栈栈顶的算符与新读入的算符进行算符优先级比较，如果新读入的算符优先级高就压入栈，
	//如果新读入外的算符优先级低就利用栈内的算符进行计算，并将计算结果压入数字栈
	stack<double> operand_stack;//数字栈
	stack<char> operator_stack;	//算符栈
	operator_stack.push('=');	//算符栈中预先压入'='，便于运算符比较操作，计算式遇到最后的'='时，计算结束
	
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
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=' ) { //算符
				while (true) {
					char ct = operator_stack.top();
					
					if (precede(ct, c) < 0) {
						//新读入的算符优先级高，算符入栈
						operator_stack.push(c);
						break;
					}
					else if (precede(ct, c) > 0) {
						//新读入的算符优先级低，根据栈顶算符计算
						double num2 = operand_stack.top();
						operand_stack.pop();
						double num1 = operand_stack.top();
						operand_stack.pop();
						double num = calc(ct, num1, num2);
						operand_stack.push(num);
						operator_stack.pop();
					}
					else if (precede(ct, c) == 0) {
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

int StackCalculator1::precede(char c1, char c2) {
	struct OPERATOR {
		char oper;			//运算符
		int priority_left;	//先出现的运算符的优先级
		int priority_right;	//后出现的运算符的优先级
	} operators[] = { { '+', 2, 1 }, { '-', 2, 1 }, { '*', 4, 3 }, { '/', 4, 3 }, { '(', 0, 5 }, { ')', 4, 0 }, { '=', 0, 0 } };
	
	auto it1 = find_if(begin(operators), end(operators), [c1](const OPERATOR& op) { return op.oper == c1; });
	auto it2 = find_if(begin(operators), end(operators), [c2](const OPERATOR& op) { return op.oper == c2; });
	return it1->priority_left - it2->priority_right;
}

double StackCalculator1::calc(char oper, double num1, double num2) {
	switch (oper) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	}
}
