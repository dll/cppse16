// TestCESMS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Company.h"

int main()
{
	Company c;
	Manager m;
	Programmer p;

	m.getPay();//1.ֱ�Ӷ���m����getPay����
	p.getPay();

	Employee &reM = m;//��������ָ���������
	c.payroll(reM);
	Employee &reP = p;//2.������ö���reP,reM����getPay����
	c.payroll(reP);
	p.getPay();//��p�仯��ʹ�û���ָ�룬��̬ת�����õ��仯�������н+����

    return 0;
}

