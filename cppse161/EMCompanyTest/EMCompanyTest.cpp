// EMCompanyTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#pragma comment(lib,"lib\\LibEmployeeManage.lib")

int main()
{
	Company c;
	Manager m;
	Programmer p;

	Employee &reM = m;
	c.payroll(reM);
	m.getPay();//1.ֱ�Ӷ���m����getPay����

	Employee &reP = p;//2.������ö���reP,reM����getPay����
	c.payroll(reP);
	p.getPay();//��p�仯��ʹ�û���ָ�룬��̬ת�����õ��仯�������н+����
	//p.getBonus();

    return 0;
}
/*
http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=29121609&id=3851844
*/