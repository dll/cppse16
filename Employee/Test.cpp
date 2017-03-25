// cppse16.cpp : 定义控制台应用程序的入口点。
#include"Employee.h"
#include<fstream>

int main(int argc, char** argv) {
	//硬编码测试
//	Employee emp("Bjarne Stroustrup", 67, 'm', 206004, 2288.99);
//	emp.Output();
//	
//	emp.Person::Output ();	//	emp.Employee::Output ();
	
	//读cin输入流
	string n;
	int a;
	char g;
	unsigned w;
	double s;
	while(cin>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		empn.Output();
	}
	
	//读文件流
	ifstream ifs("Employee.data");
	while(ifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		empn.Output();
	}
	//system("pause");
	return 0;
}
