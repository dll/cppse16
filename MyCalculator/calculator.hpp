#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
#include<cstdlib>
namespace dll{//���ֿռ�dll
	class Calculator{
		int oper1;
		int oper2;
		char oper;
		static int result;//��̬���ݳ�Ա����������м���
	public:
		Calculator(int , char, int);//���캯��
		Calculator(char,int);//�������㹹�캯��
		int Calculate();
		
		int Add();
		int Sub();
		int Mlt();
		int Div();
		int Mod();
		//��Ӹ��෽��/�㷨
	};
	
	//�쳣����
	class DivideByZeroException {			// �����쳣��
		std::string message;				// �쳣��Ϣ
	public:
		DivideByZeroException() : message("����Ϊ�㣡") {};	// ���캯��
		std::string what() { return message; }
	};
	class DivideByZero {};				// ����һ�����࣬0������
	class OperationTypeNoExist {};		// ����һ�����࣬�������Ͳ�����
}

#endif
