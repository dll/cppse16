#pragma once
#include<iostream>
#include<string>

namespace myCalculator {
	class Calculator {
	//private:
		double operand1;
		double operand2;
		char   myOperator;//operator��C++�Ĺؼ���
	public:
		Calculator(double num1, char oper, double num2);//���캯��
		double Calculate();//ѡ�����
		double Add();//�ӷ�
		double Sub();//����
		double Mod();//ȡģ/����
		double Div();//����
	};
	//�ο�P52
	class DivideByZeroException {
		std::string message;
	public:
		DivideByZeroException() :message("����Ϊ�㣡") {}
		std::string what() { return message; }
	};
}
