// Time.cpp : �������̨Ӧ�ó������ڵ㡣

#include "Time.h"

int main(){
	Time time1(12, 59, 59);
	Time time2(3, 59, 59);
	Time time3(5, 5, 5);
	Time time0(0, 0, 0);
	time1.Display();
	time2.Display();
	time0 = time1 + time2;//����Time���󣬿��������������������
	time0.Display();
	time0 = time1 + time2 + time3;
	time0.Display();
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
	t3.Display();
	Time t4("11:33:44");//���ַ�����ʽ����һ����׼ʱ���ʽ
	t4.Display();
	cout << t4 << endl;

	Time t5;//û��Ĭ�Ϲ��캯��
	cout << "��ʹ��>>����,<<���������ĳһʱ��:" << endl;
	cin >> t5;
	cout << t5<<endl;

	return 0;
}
/*
12:59:59
03:59:59
16:59:58
22:05:03
22:05:03
11:33:44
11:33:44
��ʹ��>>����,<<���������ĳһʱ��:
20 28 12
20:28:12
�밴���������. . .
*/

