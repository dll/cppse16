// cppse16.cpp : 定义控制台应用程序的入口点。
#include"Manager.h"
#include<fstream>

int main(int argc, char** argv) {
	//硬编码测试
//	Employee emp("Bjarne Stroustrup", 67, 'm', 206004, 2288.99);
//	emp.Output();
//	emp.Person::Output ();	//	emp.Employee::Output ();
//	
//	Manager m("Bjarne Stroustrup", 67, 'm', 206004, 2288.99,"Project Manager");
//	m.Output();
	//读cin输入流
	string n;
	int a;
	char g;
	unsigned w;
	double s;
//	while(cin>>n>>a>>g>>w>>s){
//		Employee empn(n,a,g,w,s);
//		empn.Output();
//	}
	
	//读文件流
//	ifstream ifs("Employee.data");
//	while(ifs>>n>>a>>g>>w>>s){
//		Employee empn(n,a,g,w,s);
//		empn.Output();
//	}
//	ifs.close();
	
	string p;
	ifstream ifs1("Manager.txt");
	while(ifs1>>n>>a>>g>>w>>s>>p){
		Manager man(n,a,g,w,s,p);
		man.Output();
	}

	ifs1.close();
	//system("pause");
	return 0;
}
