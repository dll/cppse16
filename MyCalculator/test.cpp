#include"Calculator.hpp"
using namespace std;
using namespace dll;

int main(){
	int a,b,r=0;char o;
	cout << "��ʼ��������" << r << endl;
	cout<<"���������뱻����������������������"<<endl;
	try {
		cout << "�˴μ�������" << r << endl;
		cout<<"����������������������"<<endl;
	}
	catch (DivideByZero) {
		cout << "����Ϊ0��" << endl;
	}
	catch (OperationTypeNoExist) {
		cout << "û�����ֲ������ͣ�" << endl;
	}
	catch (...) {
		cout << "���������쳣��" << endl;
	}
	cout << "����������" << r << endl;
	
	return 0;
}