// dowhile.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	int i = 0;
	int sum = 0;
	do {
		sum += i++;
	} while (i <= 100);
	cout << sum << endl;

    return 0;
}

