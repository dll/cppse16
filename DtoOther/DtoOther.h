#ifndef DTOOTHER_H
#define DTOOTHER_H

#include <stack>// 用双向链表作堆栈的底层结构

class DtoOther {
	private:		int decimalNumber;		int numberSystem;	public:		DtoOther(int,int);	// 构造函数		void convert();		// 转换函数
};

#endif

