#include "Calculator.hpp"
int main() {
	//Calculator cacl0(2,'A',3);//����һ������������
	//cout <<"������Ϊ:"<< cacl0.calChoose_ie() << endl;
	/*
	Calculator cacl1(2,'+',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl1.calChoose_ie() << endl;
	Calculator cacl2(2,'-',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl2.calChoose_ie() << endl;
	Calculator cacl3(2,'*',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl3.calChoose_sc() << endl;
	Calculator cacl4(2,'/',3);		// ����һ������������
	cout<<"������Ϊ��"<< cacl4.calChoose_sc() << endl;

	Calculator cacl5 (2,'/', 0); // ����һ������������
	//cout <<"������Ϊ��"<< cacl5.calChoose_sc() << endl;
	//cout <<"������Ϊ��"<< cacl5.calChoose_exp() << endl;
	cout <<"������Ϊ��"<< cacl5.calChoose_exp1() << endl;

	try{					// ���
		Calculator cacl5 (2,'/',0);		// ���Ա�0������
		cout << "������Ϊ��"<< cacl5.calChoose_exp2() << endl;
	}
	catch (int){				// �ٲ��񲢴���int�����쳣
		cerr << "����Ϊ0" << endl;
	}

	try{
		Calculator cacl3 (2,'A',3);				// ���Բ����ڲ���
		std::cout << "������Ϊ��"<< cacl3.calChoose_exp3() << std::endl;
		Calculator cacl4 (2,'/',0);				// ���Ա�0��
		std::cout << "������Ϊ��"<< cacl4.calChoose_exp3() << std::endl;
	}
	catch (int){						// ���񲢴���int�����쳣
		cerr << "����Ϊ0" << endl;
	}
	catch(char){ 						// ���񲢴���char�����쳣
		cerr << "�������������!" << endl;
	}

	try{
		Calculator cacl3 (2,'A',3);		// ����һ������������
		std::cout << "������Ϊ��"<< cacl3.calChoose_exp4() << std::endl;
		Calculator cacl4 (2,'/',0);		// ����һ������������
		std::cout << "������Ϊ��"<< cacl4.calChoose_exp4() << std::endl;
	}
	catch (DivideByZeroException ex){		// ���񲢴���int�����쳣
		cerr << "����Ϊ0" << endl;
	}
	catch(char){ 				// ���񲢴���char�����쳣
		cerr << "�������������!" << endl;
	}
	//���Ա�0����������
	try{
		Calculator cacl4 (2,'/',0);		// ����һ������������
		std::cout << "������Ϊ��"<< cacl4.calChoose_exp5() << std::endl;
	}
	catch(DivideByZero){			// ����0���쳣������
		std::cout << "����Ϊ0��" << std::endl;
	}
	catch(OperationTypeNoExist)	{	// �����޲��������쳣������
		std::cout << "û�����ֲ������ͣ�" << std::endl;
	}
	//���Բ������Ͳ�����
	try{
		Calculator cacl4 (2,'A',3);		// ����һ������������
		std::cout << "������Ϊ��"<< cacl4.calChoose_exp5() << std::endl;
	}
	catch(DivideByZero){
		std::cout << "����Ϊ0��" << std::endl;
	}
	catch(OperationTypeNoExist)	{
		std::cout << "û�����ֲ������ͣ�" << std::endl;
	}*/

	//�����κ��쳣...
	int number1, number2;
	char op;

	std::cout << "������һ����ʽ��";
	std::cin >> number1 >> op >> number2;

	try {
		Calculator cacl(number1, op, number2);
		std::cout << "������Ϊ��" << cacl.calChoose_exp5() << std::endl;
	}
	catch (DivideByZero) {
		std::cout << "����Ϊ0��" << std::endl;
	}
	catch (OperationTypeNoExist) {
		std::cout << "û�����ֲ������ͣ�" << std::endl;
	}
	catch (...) {
		std::cout << "���������쳣��" << std::endl;
	}

	return 0;
}