// TestCESMS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Company.h"

int main()
{
	Company c;
	Manager m;
	Programmer p;

	m.getPay();//1.直接对象m调用getPay方法
	p.getPay();

	Employee &reM = m;//父类引用指向子类对象
	c.payroll(reM);
	Employee &reP = p;//2.间接引用对象reP,reM调用getPay方法
	c.payroll(reP);
	p.getPay();//当p变化后，使用基类指针，动态转换，得到变化结果“基薪+奖金”

    return 0;
}

