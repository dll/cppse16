#include "Calculator.hpp"

using namespace dll;

int main () {
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
	double number1,number2,result;
	char op;
	/*
	{
		std::cout << "����ʽ1�����ݳ�Աnumber1�洢�м���\n������һ����ʽ��";
		std::cin >> number1 >> op >> number2;
		dll::Calculator cacl1(number1, op, number2);
		std::cout << "������Ϊ��" << (number1 = cacl1.Calculate()) << std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl2(op, number2);//���ع��캯��
		std::cout << "������Ϊ��" << (number1 = cacl2.Calculate()) << std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl3(op, number2);//���ع��캯��
		std::cout << "������Ϊ��" << cacl3.Calculate() << std::endl;
	}
	{
		std::cout << "\n\n����ʽ2����̬�ֲ������洢�м���\n������һ����ʽ��";
		std::cin >> number1 >> op >> number2;
		dll::Calculator cacl11(number1, op, number2);
		std::cout << "������Ϊ��" << cacl11.Calculate()<< std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl22(op, number2);//���ع��캯��
		std::cout << "������Ϊ��" << cacl22.Calculate()<< std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl33(op, number2);//���ع��캯��
		std::cout << "������Ϊ��" << cacl33.Calculate() << std::endl;
	}
	{
		std::cout << "\n\n����ʽ3����̬��Ա�����洢�м���\n������һ����ʽ��";
		std::cin >> number1 >> op >> number2;
		dll::Calculator cacl111(number1, op, number2);
		std::cout << "������Ϊ��" << cacl111.Calculate() << std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl222(op, number2);//���ع��캯��
		std::cout << "������Ϊ��" << cacl222.Calculate() << std::endl;
		std::cin >> op >> number2;
		dll::Calculator cacl333(op, number2);//���ع��캯��
		std::cout << "������Ϊ��" << cacl333.Calculate() << std::endl;
	}

	{
		std::cout << "\n\n�������ʽ4���ظ��ṹwhile\n������һ����ʽ��";
		try {
		}
		catch (DivideByZero) {
			std::cout << "����Ϊ0��" << std::endl;
		}
		catch (dll::OperationTypeNoExist) {
			std::cout << "û�����ֲ������ͣ�" << std::endl;
		}
		catch (...) {
			std::cout << "���������쳣��" << std::endl;
		}
		std::cout << "��������" << result << std::endl;
	}	*/
	{
		std::cout << "\n\n�������ʽ5���ظ��ṹdo-while\n";
		try {
		}
		catch (DivideByZero) {
			std::cout << "����Ϊ0��" << std::endl;
		}
		catch (dll::OperationTypeNoExist) {
			std::cout << "û�����ֲ������ͣ�" << std::endl;
		}
		catch (...) {
			std::cout << "���������쳣��" << std::endl;
		}
		std::cout << "��������" << result << std::endl;
	}

	system("pause");

	return 0;
}