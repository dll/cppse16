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
	//if (myOperator == '+')//һ�����/����֧���ӷ�
	if (myOperator == '+')//�������/˫��֧���ӻ��
		return Add();
	else if (myOperator == '-')//���֧
		return Sub();
	else if (myOperator == '%')
		return Mod();
	else if (myOperator == '/')
		return Div();
	else {
		std::cout<< "\n�������������" << std::endl;
		system("pause");
		exit(1);
	}
}