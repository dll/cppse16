#pragma once

#include <iostream>	
#include <cstdlib>	
using namespace std;

class Calculator{
private:
	int	 operand1;//��������
	char operat;//������
	int	 operand2;//������
public:
	Calculator(int num1, char op, int num2); // ���캯��
	int	add();				    // �����㺯��
	int sub();				    // �����㺯��
	int mlt();				    // �����㺯��
	int div();				    // �����㺯��
	int calChoose_ie();	// ѡ���������
	int calChoose_sc();	// ѡ���������
};