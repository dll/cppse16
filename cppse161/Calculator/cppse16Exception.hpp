#pragma once
#include <iostream>
#include <string>						// 嵌入字符串类声明
class DivideByZeroException{			// 定义异常类
	std::string message;				// 异常信息
public:
	DivideByZeroException ( ): message ("除数为零！") {};	// 构造函数
	std::string what( ) {return message;}
};

class DivideByZero {};				// 定义一个空类，0除错误
class OperationTypeNoExist {};		// 定义一个空类，操作类型不存在