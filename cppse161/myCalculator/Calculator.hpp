#pragma once
#include<iostream>
#include<string>

namespace myCalculator {
	class Calculator {
	//private:
		double operand1;
		double operand2;
		char   myOperator;//operator是C++的关键字
	public:
		Calculator(double num1, char oper, double num2);//构造函数
		double Calculate();//选择计算
		double Add();//加法
		double Sub();//减法
		double Mod();//取模/求余
		double Div();//除法
	};
	//参考P52
	class DivideByZeroException {
		std::string message;
	public:
		DivideByZeroException() :message("除数为零！") {}
		std::string what() { return message; }
	};
}
