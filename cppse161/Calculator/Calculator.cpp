#include"Calculator.hpp"

using namespace std;
using namespace dll;

Calculator::Calculator(double num1,char op,double num2)  {	// ���캯����ʵ�֣�����
	operand1 = num1;		
	operat = op; 
	operand2 = num2; 
	result = operand1;
}
Calculator::Calculator(char op, double num2) {	// ���캯�����ص�ʵ�֣�����
	operat = op;
	operand2 = num2;
}
double Calculator::result = 0;

double Calculator::add ()  { 		// �����㺯����ʵ��
	return operand1 + operand2; 
}
double Calculator::sub ()	  {		// �����㺯����ʵ��
	return operand1 - operand2; 
}
double Calculator::mlt ()	 {		// �����㺯����ʵ��
	return operand1 * operand2; 
}
double Calculator::div ()	 {		// �����㺯����ʵ��
	if(operand2 == 0)
		//throw -1;
		throw DivideByZero();	// ����0���쳣
	return operand1 / operand2; 
}

double Calculator::calChoose_ie() {
	if (operat =='+')
		return add ();
	else if (operat =='-')
		return sub ();
	else if (operat =='*')
		return mlt ();
	else if (operat =='/')
			 return div ();
	else {
		std::cout << "\n�������������!";
		exit (1);
	}
}
double Calculator::calChoose_sc() {
	switch (operat)  {
	case '+':
		return add ();break;
	case '-':
		return sub ();break;
	case '*':
		return mlt ();break;
	case '/':
		return div ();break;
	default:
		std::cout << "\n�������������!";
		exit (1);
	}
}

double Calculator::calChoose_exp() {
	switch (operat)  {
	case '+':
		return add ();break;
	case '-':
		return sub ();break;
	case '*':
		return mlt ();break;
	case '/':
		try{
			if(operand2 == 0)
				throw -1;	// ����0���쳣����һ��������ʾ
			else{
				return div ();break;
			}
		}
		catch (double){			// �������������쳣
			cerr << "����Ϊ0" << endl;
			exit (1);
		}
	default:
			   cout << "\n�������������!";
			   exit (1);
	}
} 
double Calculator::calChoose_exp1() {
	try{				// ����쳣
		switch (operat) {
		case '+':
			return add ();break;
		case '-':
			return sub ();break;
		case '*':
			return mlt ();break;
		case '/':
			return div ();break;
		default:
			cout << "\n�������������!";
			exit (1);
		}
	}
	catch(double){			// ���񲢴����쳣
		std::cerr<<"����Ϊ0"<<std::endl;
		exit (1);
	}
} 

double Calculator::calChoose_exp2() {
	try{				// ����쳣
		switch (operat) {
		case '+':
			return add ();break;
		case '-':
			return sub ();break;
		case '*':
			return mlt ();break;
		case '/':
			return div ();break;
		default:
			cout << "\n�������������!";
			exit (1);
		}
	}
	catch(double){		// ����������
		throw;
	}
} 

double Calculator::calChoose_exp3() {
	switch (operat) {
	case '+':
		return add();break;
	case '-':
		return sub();break;
	case '*':
		return mlt();break;
	case '/':
		if(operand2== 0)
			throw -1;			// ��һ����������0���쳣
		else{
			return div();break;
		}
	default:
			throw 'e';
	}
} 
double Calculator::calChoose_exp4() {
	switch (operat) {
	case '+':
		return add ();break;
	case '-':
		return sub ();break;
	case '*':
		return mlt ();break;
	case '/':
		if(operand2== 0)
			throw DivideByZeroException ( );	 // �׳������쳣����
		else{
			return div ();break;
		}
	default:
			throw 'e';
	}
} 

double Calculator::calChoose_exp5() {
	try{
		switch (operat) {
		case '+':
			return add ();break;
		case '-':
			return sub ();break;
		case '*':
			return mlt ();break;
		case '/':
			return div ();break;
		default:
			throw OperationTypeNoExist();// �����޲��������쳣		
		}
	}
	catch(DivideByZero){								
		throw;				// �ٴ�����
	}
	catch(dll::OperationTypeNoExist)	{						
		throw;				// �ٴ�����
	}
}
/*
double Calculator::Calculate(){
	try {
		switch (operat) {
		case '+':
			return operand1 + operand2; break;
		case '-':
			return operand1 - operand2; break;
		case '*':
			return operand1 * operand2; break;
		case '/':
			return operand1 / operand2; break;
		default:
			throw OperationTypeNoExist();
		}
	}
	catch (OperationTypeNoExist) {
		throw;
	}
}*/

double Calculator::Calculate() {
	//static double result = operand1;
	operand1 = result;
	try {
		switch (operat) {
		case '+':
			return result = operand1 + operand2; break;
		case '-':
			return result = operand1 - operand2; break;
		case '*':
			return result = operand1 * operand2; break;
		case '/':
			return result = operand1 / operand2; break;
		default:
			throw OperationTypeNoExist();
		}
	}
	catch (OperationTypeNoExist) {
		throw;
	}
	return result;
}