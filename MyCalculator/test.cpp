#include"Calculator.hpp"
using namespace std;
using namespace dll;

int main(){
	int a,b,r=0;char o;
	cout << "开始计算结果：" << r << endl;
	cout<<"请依次输入被操作数，操作符，操作数"<<endl;
	try {		cin>>a>>o>>b;		Calculator cal7(a, o, b);		r = cal7.Calculate();
		cout << "此次计算结果：" << r << endl;
		cout<<"请继续输入操作符，操作数"<<endl;		while (cin >> o, o!= '=') {			cin >> b;			Calculator cal8(o, b);			r = cal8.Calculate();			cout << "此次计算结果：" << r << endl;		}
	}
	catch (DivideByZero) {
		cout << "除数为0！" << endl;
	}
	catch (OperationTypeNoExist) {
		cout << "没有这种操作类型！" << endl;
	}
	catch (...) {
		cout << "出现其它异常！" << endl;
	}
	cout << "最后计算结果：" << r << endl;
	
	return 0;
}
