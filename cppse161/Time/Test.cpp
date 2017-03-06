// Time.cpp : 定义控制台应用程序的入口点。
//

#include "Time.h"


int main()
{
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

	return 0;
}