#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
#include<cstdlib>
namespace dll{//名字空间dll
	class Calculator{
		int oper1;
		int oper2;
		char oper;
		static int result;//静态数据成员，保存计算中间结果
	public:
		Calculator(int , char, int);//构造函数
		Calculator(char,int);//连续计算构造函数
		int Calculate();
		
		int Add();
		int Sub();
		int Mlt();
		int Div();
		int Mod();
		//添加更多方法/算法
	};
	
	//异常处理
	class DivideByZeroException {			// 定义异常类
		std::string message;				// 异常信息
	public:
		DivideByZeroException() : message("除数为零！") {};	// 构造函数
		std::string what() { return message; }
	};
	class DivideByZero {};				// 定义一个空类，0除错误
	class OperationTypeNoExist {};		// 定义一个空类，操作类型不存在
}

#endif
