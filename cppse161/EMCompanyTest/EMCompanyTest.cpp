// EMCompanyTest.cpp : 定义控制台应用程序的入口点。
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
	m.getPay();//1.直接对象m调用getPay方法

	Employee &reP = p;//2.间接引用对象reP,reM调用getPay方法
	c.payroll(reP);
	p.getPay();//当p变化后，使用基类指针，动态转换，得到变化结果“基薪+奖金”
	//p.getBonus();

    return 0;
}
/*
http://blog.chinaunix.net/xmlrpc.php?r=blog/article&uid=29121609&id=3851844
*/