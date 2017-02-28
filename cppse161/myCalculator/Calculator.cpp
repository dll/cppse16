#include"Calculator.hpp"
using namespace myCalculator;

Calculator::Calculator(double num1, char oper, double num2) {
	operand1 = num1;
	myOperator = oper;
	operand2 = num2;
}

double Calculator::Add() {
	return operand1 + operand2;
}
double Calculator::Sub() {
	return operand1 - operand2;
}

double myCalculator::Calculator::Mod()//添加名字空间myCalculator
{
	return int(operand1) % int(operand2);
}
/*
5.85
0.43
1
1.5
依次输入被操作数，操作符，操作数
6 / 0
inf
请按任意键继续. . .
*/
double myCalculator::Calculator::Div()
{
	//异常处理与逻辑代码混杂
	//if (operand2 == 0) {
	//	std::cout << "除数不能为零!" << std::endl;
	//	system("pause");
	//	exit(0);
	//}
	//else
	if (operand2 == 0)
		throw DivideByZeroException();
	return operand1 / operand2;
}

double Calculator::Calculate() {
	//if (myOperator == '+')//一种情况/单分支：加法
	if (myOperator == '+')//两种情况/双分支：加或减
		return Add();
	else if (myOperator == '-')//多分支
		return Sub();
	else if (myOperator == '%')
		return Mod();
	else if (myOperator == '/')
		return Div();
	else {
		std::cout<< "\n操作符输入错误！" << std::endl;
		system("pause");
		exit(1);
	}
}