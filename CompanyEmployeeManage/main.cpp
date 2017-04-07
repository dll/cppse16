#include<iostream>

#include "Employee.h"
#include "Manager.h"
#include "Programmer.h"
#include "Company.h"

using namespace std;

   int main (int argc, char *argv[]) {
	Company c;
	Manager m;
	Programmer p;
	m.getPay();//1.直接对象m或p调用getPay方法显示员工工资
	p.getPay();
	Employee &reP=p;//2.间接引用对象reP调用getPay方法显示员工工资
	reP.getPay();
	Employee *pe=&m;//3.间接指针对象pe->m,pe->p调用getPay方法显示员工工资
	pe->getPay();
	pe=&p;
	pe->getPay();
	//pe->getBonus();//error: 'class Employee' has no member named 'getBonus'
	c.payroll(reP);//4.更好的，可以动态扩展功能的多态应用
	c.payroll(pe);//4.更好的，可以动态扩展功能的多态应用
	return 0;
}

