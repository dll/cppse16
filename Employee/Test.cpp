// Test.cpp : 定义控制台应用程序的入口点。
#include"Employee.h"

int main() {

	std::cout << "构造函数及其重载演示\n" << std::endl;
	Employee empl1;
	empl1.printEmployee();

	Employee empl2("zhangsan", 28, 'f');
	empl2.printEmployee();

	Employee empl3("Lisi", 25, 'm', 2345.67F);//test.cpp(11): warning C4305: “参数”: 从“double”到“float”截断
	empl3.printEmployee();

	Employee empl4(empl3);
	empl3.printEmployee();

	std::cout << "\n指向对象的指针演示" << std::endl;
	Employee *pEmp=NULL;
	pEmp = &empl2;
	pEmp->printEmployee();
	pEmp = &empl3;
	pEmp->printEmployee();
	pEmp = &empl4;
	pEmp->printEmployee();

	std::cout << "\n引用演示" << std::endl;
	Employee & rEmp = empl2;
	rEmp.printEmployee();

	Employee & rEmp1 = empl3;
	rEmp1.printEmployee();

	std::string n; 
	int a;
	char g;
	float s;
	std::cout << "请输入职员数据:" << std::endl;
	std::cin >> n >> a >> g >> s;
	Employee *dEmpl = new Employee(n, a, g, s);
	(*dEmpl).printEmployee();
	delete dEmpl;

	return 0;
}