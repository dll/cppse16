#include"Calculator.hpp"

int Calculator::add ()  { 		// 加运算函数的实现
	return operand1 + operand2; 
}
int Calculator::sub ()	  {		// 减运算函数的实现
	return operand1 - operand2; 
}
int Calculator::mlt ()	 {		// 乘运算函数的实现
	return operand1 * operand2; 
}
int Calculator::div ()	 {		// 除运算函数的实现
	return operand1 / operand2; 
}
int Calculator::calChoose_ie() {
	if (operat =='+')
		return add ();
	else if (operat =='-')
		return sub ();
	else if (operat =='*')
		return mlt ();
	else if (operat =='/')
			 return div ();
	else {
		std::cout << "\n操作符输入错误!";
		exit (1);
	}
}
int Calculator::calChoose_sc() {
	switch (operat)  {
	case '+':
		return add ();break;
	case '-':
		return sub ();break;
	case '*':
		return mlt ();break;
	case '/':
		return div ();break;
	default:
		std::cout << "\n操作符输入错误!";
		exit (1);
	}
}
Calculator::Calculator(int num1, char op, int num2) {	// 构造函数的实现
	operand1 = num1;
	operat = op;
	operand2 = num2;
}