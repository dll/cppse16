#include"Calculator.hpp"
using namespace myCalculator;

Calculator::Calculator(double num1, char oper, double num2) {
	operand1 = num1;
	myOperator = oper;
	operand2 = num2;
}
double Calculator::Add() {	return operand1 + operand2;}
double Calculator::Sub() {	return operand1 - operand2;}
double myCalculator::Calculator::Mod(){	return int(operand1) % int(operand2);}
double myCalculator::Calculator::Div(){
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