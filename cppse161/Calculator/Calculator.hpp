#pragma once

#include <iostream>	
#include <cstdlib>	//system,exit����

#include"Exception.hpp"

namespace dll{//cn_edu_chzu_dxxy_se16
	class Calculator {
	private:
		double	 operand1;//��������
		char operat;//������
		double	 operand2;//������
		static double result;
	public:
		Calculator(double num1,char op,double num2);  // ���캯��
		Calculator(char op, double num2);  // ���캯������
		double add ();				    // �����㺯��
		double sub ();				    // �����㺯��
		double mlt ();				    // �����㺯��
		double div ();				    // �����㺯��
		double calChoose_ie();	// ѡ���������
		double calChoose_sc();	// ѡ���������
		double Calculate();//ѡ���������
		
		double calChoose_exp();//��ͬһ�������������봦��
		double calChoose_exp1();//�������쳣���⴦����ڲ�ͬ������
		double calChoose_exp2();//��������쳣
		double calChoose_exp3();//��������쳣
		double calChoose_exp4();//�Զ����쳣��
		double calChoose_exp5();//�ÿ�����Ϊ�쳣��
	};
}//û�зֺ�