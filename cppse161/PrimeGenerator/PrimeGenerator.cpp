#include<iostream>

#include"PrimeGenerator.h"

using namespace std;

PrimeGenerator::PrimeGenerator(int l, int u)
	:lowerNaturalNumber(l), upperNaturalNumber(u), count(0) {}

void PrimeGenerator::getPrimeSequence() {
	cout << lowerNaturalNumber << "  到  " << upperNaturalNumber << "之间的素数序列为：" << endl;
	if (lowerNaturalNumber > upperNaturalNumber) {	// 区间界限输入反时交换
		int temp = lowerNaturalNumber;
		lowerNaturalNumber = upperNaturalNumber;
		upperNaturalNumber = temp;
	}
	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// 循环控制
		if (m < 2)
			continue;// 短路一次循环中后面的部分
		if (isPrime(m)) {
			//cout << m << ", ";
			count++;
			printPrime(1, m);
		}
	}
	cout << "\n共： " << count << " 质数！" << endl;
}

bool PrimeGenerator::isPrime(int number) {
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// 发现number能被一个数整除，就断定它不是素数
		}
	}
	return true;	// 测试结束还没有被任何数整除，断定为素数
}

void PrimeGenerator::getPrimeSequenceNestFor() {
	cout << lowerNaturalNumber << "  到  " << upperNaturalNumber << "之间的素数序列为：" << endl;
	if (lowerNaturalNumber > upperNaturalNumber) {	// 区间界限输入反时交换
		int temp = lowerNaturalNumber;
		lowerNaturalNumber = upperNaturalNumber;
		upperNaturalNumber = temp;
	}
	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// 循环控制
		if (m < 2)
			continue;// 短路一次循环中后面的部分
					 //if (isPrime(m))
					 //	cout << m << ", ";
		bool flag = true;
		for (int n = 2; n < m; n++) {
			flag = true;
			if (m % n == 0) {
				flag = false;	// 能被一个数整除，就断定它不是素数
				break;
			}
		}
		if (flag == true) {
			//std::cout<< m<<", ";
			count++;
			printPrime(2, m);
		}
	}
	cout << "\n共： " << count << " 质数！" << endl;
}

void PrimeGenerator::printPrime(int style, int data) {
	static int c = 0;//col
	static int r = 1;//row
	static int n = 1;
	if (style == 1) {
		cout << setw(3) << data << " ";
		c++;
		if (c % 5 == 0)
			cout << endl;
	}
	else if (style == 2) {
		cout << setw(3) << data << " ";
		c++;
		if (n <= c) {
			cout << endl;
			c = 0;
			n = ++r;
		}
	}
	else
		cout << setw(3) << data << " ";
}
