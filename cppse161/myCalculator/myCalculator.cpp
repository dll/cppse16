// myCalculator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Calculator.hpp"

using namespace std;
using namespace myCalculator;
int main(){
	Calculator cal1(3.14, '+', 2.71);//һ����ʽ��һ�ּӷ�
	cout << cal1.Calculate() << endl;
	Calculator cal2(3.14, '-', 2.71);//�ڶ�����ʽ������
	cout << cal2.Calculate() << endl;
	Calculator cal3(3.14, '%', 2.71);//��������ʽ�����ࣺע�⣺ֻ�������������࣡3%2
	cout << cal3.Calculate() << endl;
	Calculator cal4(3, '/', 2);//������ʽ
	cout << cal4.Calculate() << endl;

	double x, y;
	char op;
	cout << "�������뱻����������������������" << endl;
	cin >> x >> op >> y;//�������뱻����������������������
	Calculator cal5(x, op, y);
	try {		cout << cal5.Calculate() << endl;	}
	catch (DivideByZeroException ex) {		cerr << ex.what() << endl;	}

	system("pause");
    return 0;
}