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
	
	Employee &reM=m;
	c.payroll(reM);
	//m.getPay();//1.直接对象m调用getPay方法
	
	Employee &reP=p;//2.间接引用对象reP,reM调用getPay方法
	c.payroll(reP);
	//p.getPay();
	
	Employee *pe=&m;//3.间接指针对象pe->m,->p调用getPay方法
	pe->getPay();
	pe=&p;
//	pe->getPay();
//	pe->getBonus();//切割??
	p.getBonus();
	
	return 0;
}

