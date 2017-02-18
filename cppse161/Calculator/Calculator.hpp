#pragma once

#include <iostream>	
#include <cstdlib>	

#include"Exception.hpp"

namespace dll{//cn_edu_chzu_dxxy_se16
	class Calculator {
	private:
		int	 operand1;//被运算数
		char operat;//操作符
		int	 operand2;//运算数
	public:
		Calculator (int num1,char op,int num2);  // 构造函数
		int	add ();				    // 加运算函数
		int sub ();				    // 减运算函数
		int mlt ();				    // 乘运算函数
		int div ();				    // 除运算函数
		int calChoose_ie();	// 选择操作类型
		int calChoose_sc();	// 选择操作类型
		
		int calChoose_exp();//在同一个函数中抛掷与处理
		int calChoose_exp1();//将抛掷异常与检测处理放在不同函数中
		int calChoose_exp2();//多次抛掷异常
		int calChoose_exp3();//抛掷多个异常
		int calChoose_exp4();//自定义异常类
		int calChoose_exp5();//用空类作为异常类
	};
}//没有分号