#include"Calculator.hpp"

int Calculator::add ()  { 		// �����㺯����ʵ��
	return operand1 + operand2; 
}
int Calculator::sub ()	  {		// �����㺯����ʵ��
	return operand1 - operand2; 
}
int Calculator::mlt ()	 {		// �����㺯����ʵ��
	return operand1 * operand2; 
}
int Calculator::div ()	 {		// �����㺯����ʵ��
	return operand1 / operand2; 
}
int Calculator::calChoose_ie() {
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
int Calculator::calChoose_sc() {
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
Calculator::Calculator(int num1, char op, int num2) {	// ���캯����ʵ��
	operand1 = num1;
	operat = op;
	operand2 = num2;
}