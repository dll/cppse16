#pragma once

#include <iostream>	
#include <cstdlib>	

#include"cppse16Exception.hpp"

using namespace std;

class Calculator {
private:
	int	 operand1;//��������
	char operat;//������
	int	 operand2;//������
public:
	Calculator (int num1,char op,int num2);  // ���캯��
	int	add ();				    // �����㺯��
	int sub ();				    // �����㺯��
	int mlt ();				    // �����㺯��
	int div ();				    // �����㺯��
	int calChoose_ie();	// ѡ���������
	int calChoose_sc();	// ѡ���������
	
	int calChoose_exp();//��ͬһ�������������봦��
	int calChoose_exp1();//�������쳣���⴦����ڲ�ͬ������
	int calChoose_exp2();//��������쳣
	int calChoose_exp3();//��������쳣
	int calChoose_exp4();//�Զ����쳣��
	int calChoose_exp5();//�ÿ�����Ϊ�쳣��
};