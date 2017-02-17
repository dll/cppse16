#pragma once

#include <iostream>	
#include <cstdlib>	
using namespace std;

class Calculator{
private:
	int	 operand1;//被运算数
	char operat;//操作符
	int	 operand2;//运算数
public:
	Calculator(int num1, char op, int num2); // 构造函数
	int	add();				    // 加运算函数
	int sub();				    // 减运算函数
	int mlt();				    // 乘运算函数
	int div();				    // 除运算函数
	int calChoose_ie();	// 选择操作类型
	int calChoose_sc();	// 选择操作类型
};