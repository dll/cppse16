#ifndef PriorityCalcultor_H
#define PriorityCalcultor_H
class PriorityCalcultor{
public:	
	//由字符串的表达式中，将操作数转换成数字 
	double toNum(char*s, int &k);
	//操作符的优先级：（），*/,+-,=等共四级
	int priority(char c);
	//双栈计算算术表达式
	void Calculator();
};
#endif

