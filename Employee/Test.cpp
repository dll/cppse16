// cppse16.cpp : �������̨Ӧ�ó������ڵ㡣
#include"Employee.h"
#include<fstream>

int main(int argc, char** argv) {
	//Ӳ�������
//	Employee emp("Bjarne Stroustrup", 67, 'm', 206004, 2288.99);
//	emp.Output();
//	
//	emp.Person::Output ();	//	emp.Employee::Output ();
	
	//��cin������
	string n;
	int a;
	char g;
	unsigned w;
	double s;
	while(cin>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		empn.Output();
	}
	
	//���ļ���
	ifstream ifs("Employee.data");
	while(ifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		empn.Output();
	}
	//system("pause");
	return 0;
}
