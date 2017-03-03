// myCalculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Calculator.hpp"

using namespace std;
using namespace myCalculator;
int main(){
	Calculator cal1(3.14, '+', 2.71);//一个算式：一种加法
	cout << cal1.Calculate() << endl;
	Calculator cal2(3.14, '-', 2.71);//第二个算式：减法
	cout << cal2.Calculate() << endl;
	Calculator cal3(3.14, '%', 2.71);//第三个算式：求余：注意：只有整数才能求余！3%2
	cout << cal3.Calculate() << endl;
	Calculator cal4(3, '/', 2);//更多算式
	cout << cal4.Calculate() << endl;

	double x, y;
	char op;
	cout << "依次输入被操作数，操作符，操作数" << endl;
	cin >> x >> op >> y;//依次输入被操作数，操作符，操作数
	Calculator cal5(x, op, y);
	try {		cout << cal5.Calculate() << endl;	}
	catch (DivideByZeroException ex) {		cerr << ex.what() << endl;	}

	system("pause");
    return 0;
}