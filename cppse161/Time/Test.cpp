// Time.cpp : �������̨Ӧ�ó������ڵ㡣

#include "Time.h"

int main(){
	Time time1(12, 59, 59);
	Time time2(3, 59, 59);
	Time time3(5, 5, 5);
	Time time0(0, 0, 0);
	time1.display();
	time2.display();
	time0 = time1 + time2;
	time0.display();
	time0 = time1 + time2 + time3;
	time0.display();
	/*
	Time t1(23, 59, 55);
	for (int i = 0; i <= 5; i++)
		t1++.display();
	std::cout << std::endl;
	Time t2(23, 59, 55);
	for (int i = 0; i <= 5; i++)
		(++t2).display();
	std::cout << std::endl;
	*/

	Time t3 = time0;
	t3.display();
	Time t4("11:33:44");
	t4.display();
	cout << t4 << endl;

	Time t5;//û��Ĭ�Ϲ��캯��
	cout << "��ʹ��>>����,<<���������ĳһʱ��:" << endl;
	cin >> t5;
	cout << t5<<endl;

	return 0;
}