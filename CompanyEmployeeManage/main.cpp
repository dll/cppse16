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
	//m.getPay();//1.ֱ�Ӷ���m����getPay����
	
	Employee &reP=p;//2.������ö���reP,reM����getPay����
	c.payroll(reP);
	//p.getPay();
	
	Employee *pe=&m;//3.���ָ�����pe->m,->p����getPay����
	pe->getPay();
	pe=&p;
//	pe->getPay();
//	pe->getBonus();//�и�??
	p.getBonus();
	
	return 0;
}

