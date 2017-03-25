#include"Calculator.hpp"
using namespace std;
using namespace dll;
Calculator::Calculator(int x, char o, int y):oper1(x),oper(o),oper2(y){}
Calculator::Calculator(char o, int y):oper1(result),oper(o),oper2(y){}
int Calculator::result = 0;//静态变量，在类/函数外部赋值
int Calculator::Calculate(){
	try {
		switch (oper) {
		case '+':			return result = Add(); break;
		case '-':			return result = Sub(); break;
		case '*':			return result = Mlt(); break;
		case '/':			return result = Div(); break;
		case '%':			return result = Mod(); break;
		default:			throw OperationTypeNoExist();
		}
	}
	catch (OperationTypeNoExist) {		throw;	}
	return result;
}
Calculator::Add(){	return oper1+oper2;}
Calculator::Sub(){	return oper1-oper2;}
Calculator::Mlt(){	return oper1*oper2;}
Calculator::Div(){	
	if(oper2 == 0)
		throw DivideByZero();	// 抛掷0除异常
	return oper1/oper2;
}
Calculator::Mod(){	return oper1%oper2;}
