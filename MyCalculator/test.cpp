#include"Calculator.hpp"
using namespace std;
using namespace dll;

int main(){
	int a,b,r=0;char o;
	cout << "��ʼ��������" << r << endl;
	cout<<"���������뱻����������������������"<<endl;
	try {		cin>>a>>o>>b;		Calculator cal7(a, o, b);		r = cal7.Calculate();
		cout << "�˴μ�������" << r << endl;
		cout<<"����������������������"<<endl;		while (cin >> o, o!= '=') {			cin >> b;			Calculator cal8(o, b);			r = cal8.Calculate();			cout << "�˴μ�������" << r << endl;		}
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
