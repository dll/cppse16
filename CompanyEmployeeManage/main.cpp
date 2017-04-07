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
	m.getPay();//1.ֱ�Ӷ���m��p����getPay������ʾԱ������
	p.getPay();
	Employee &reP=p;//2.������ö���reP����getPay������ʾԱ������
	reP.getPay();
	Employee *pe=&m;//3.���ָ�����pe->m,pe->p����getPay������ʾԱ������
	pe->getPay();
	pe=&p;
	pe->getPay();
	//pe->getBonus();//error: 'class Employee' has no member named 'getBonus'
	c.payroll(reP);//4.���õģ����Զ�̬��չ���ܵĶ�̬Ӧ��
	c.payroll(pe);//4.���õģ����Զ�̬��չ���ܵĶ�̬Ӧ��
	return 0;
}

