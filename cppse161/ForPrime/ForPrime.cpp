// ForPrime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

void Prime::getPrime() {
	for (int i = lownumb; i < upnumb; i++) {
		if (isPrime(i) == true) {
			cout << i << ", ";//打印显示
			arrayPrimes[count] = i;//arrayPrimes[i] = i??
			count++;
		}
	}

}
bool Prime::isPrime(int numb) {
	if (numb == 1)
		return false;//自然数中，1不是素数
	else if (numb == 2)//唯一偶数素数
		return true;
	else {
		//3到小于numb的每一个数i，i与numb都不能除尽则是素数，否则不是素数
		for (int i = 3; i < numb; i++){
			if (numb%i == 0)
				return false;
		}
		return true;
	}
}

PrimeManager::PrimeManager(const Prime& p) {//常量引用类型，确保P不被修改，改写构造函数
	dArray = NULL;
	count = p.count;
	dArray = new int[count];
	if (!dArray)
		throw - 1;//如果系统没有成功分配空间，则抛出异常
	for (int i = 0; i < count; i++)
		dArray[i] = p.arrayPrimes[i];
}

//打印素数金字塔
void PrimeManager::PrimePyramid() {
	int col = 0;//列
	int row = 1;//行
	int rows = 0;//行数
	int level = 0;//层（即行）
	
	//for循环是为了得到区间的素数按照1层1个，2层2，3层3,,,n-1层n-1个，n层则不定，为剩余的素数
	for (int i = 0; i < count; i++) {
		col++;
		if (rows <= col) {
			col = 0;
			rows = ++row;
			level++;
		}
	}
	col = 0; row = 1; rows = 1;//三个数字复位
	int levels = level;//总层数
	//打印金字塔
	for (int i = 0; i < count; i++) {
		if (levels == level - row + 1) {
			for (int j = 0; j <= levels; j++)
				cout << setw(2) << " ";//打印左边空格，*显示
			levels--;
		}
		cout << setw(3) << dArray[i] << " ";//动态数组
		col++;
		if (rows <= col) {
			cout << endl;//每行只有一个换行
			col = 0;
			rows = ++row;
		}
	}
	cout << endl;
}
void PrimeManager::PrimePrint() {//常量引用类型，确保P不被修改
	cout << "\n\nPrimeManager Print " << count << " Primes:" << endl;
	for (int i = 1; i <= count; i++)
		if (i % 6 == 0) {//每行6个素数
			cout << setw(3) << dArray[i - 1] << " " << endl;//setw(3),占三个字符宽度
		}
		else
			cout << setw(3) << dArray[i - 1] << " ";
	cout << endl;
}
PrimeManager::~PrimeManager() {
	if (dArray != NULL)
		delete[] dArray;//释放构造函数分配的空间
}