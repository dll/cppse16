// Test.cpp : �������̨Ӧ�ó������ڵ㡣
#include"Employee.h"

int main() {

	std::cout << "���캯������������ʾ\n" << std::endl;
	Employee empl1;
	empl1.printEmployee();

	Employee empl2("zhangsan", 28, 'f');
	empl2.printEmployee();

	Employee empl3("Lisi", 25, 'm', 2345.67F);//test.cpp(11): warning C4305: ��������: �ӡ�double������float���ض�
	empl3.printEmployee();

	Employee empl4(empl3);
	empl3.printEmployee();

	std::cout << "\nָ������ָ����ʾ" << std::endl;
	Employee *pEmp=NULL;
	pEmp = &empl2;
	pEmp->printEmployee();
	pEmp = &empl3;
	pEmp->printEmployee();
	pEmp = &empl4;
	pEmp->printEmployee();

	std::cout << "\n������ʾ" << std::endl;
	Employee & rEmp = empl2;
	rEmp.printEmployee();

	Employee & rEmp1 = empl3;
	rEmp1.printEmployee();

	std::string n; 
	int a;
	char g;
	float s;
	std::cout << "������ְԱ����:" << std::endl;
	std::cin >> n >> a >> g >> s;
	Employee *dEmpl = new Employee(n, a, g, s);
	(*dEmpl).printEmployee();
	delete dEmpl;

	return 0;
}