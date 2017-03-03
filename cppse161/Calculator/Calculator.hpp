#pragma once

#include <iostream>	
#include <cstdlib>	//system,exit函数

#include"Exception.hpp"

namespace dll{//cn_edu_chzu_dxxy_se16
	class Calculator {
	private:
		double	 operand1;//被运算数
		char operat;//操作符
		double	 operand2;//运算数
		static double result;
	public:
		Calculator(double num1,char op,double num2);  // 构造函数
		Calculator(char op, double num2);  // 构造函数重载
		double add ();				    // 加运算函数
		double sub ();				    // 减运算函数
		double mlt ();				    // 乘运算函数
		double div ();				    // 除运算函数
		double calChoose_ie();	// 选择操作类型
		double calChoose_sc();	// 选择操作类型
		double Calculate();//选择操作类型
		
		double calChoose_exp();//在同一个函数中抛掷与处理
		double calChoose_exp1();//将抛掷异常与检测处理放在不同函数中
		double calChoose_exp2();//多次抛掷异常
		double calChoose_exp3();//抛掷多个异常
		double calChoose_exp4();//自定义异常类
		double calChoose_exp5();//用空类作为异常类
	};
}//没有分号