#include "stdafx.h"

using namespace std;

int main(){
	int low, up;
	cout << "请输入生成素数的区间：" << endl;
	cin >> low >> up;
	//确保low<up
	if (low > up)
	{ low = low + up; up = low - up; low = low - up; }

	Prime p1(low, up);
	p1.getPrime();

	PrimeManager PM(p1);
	//PM.PrimePrintSA();//打印静态数组中的素数，不超过MAXCOUNT(256)
	PM.PrimePyramid();//打印素数金字塔，请参考git仓库中的实现过程
	PM.PrimePrint();//可打印超过256个素数

	return 0;
}

