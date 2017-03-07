#include<iostream>

#include"PrimeGenerator.h"

using namespace std;

PrimeGenerator::PrimeGenerator(int l, int u)
	:lowerNaturalNumber(l), upperNaturalNumber(u), count(0){}

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
			arraySavePrimes[count] = m;
			count++;
			printPrime1( m);
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
			arraySavePrimes[count] = m;
			count++;
			printPrime2(m);
		}
	}
	cout << "\n共： " << count << " 质数！" << endl;
}

void PrimeGenerator::printPrime1(int data) {
	static int c = 0;//col
	cout << setw(3) << data << " ";
	c++;
	if (c % 5 == 0)
		cout << endl;
}
void PrimeGenerator::printPrime2(int data) {
	static int c = 0;//col
	static int r = 1;//row
	static int n = 1;//col_num
	cout << setw(3) << data << " ";
	c++;
	if (n <= c) {
		cout << endl;
		c = 0;
		n = ++r;
	}
}
void PrimeGenerator::printPrime3() {
	int c = 0;//col
	int r = 1;//row
	int n = 0;//row num

	int l = 0;//level

	for (int i = 0; i < count; i++) {
		//cout << setw(3) << arraySavePrimes[i] << " ";
		c++;
		if (n <= c) {
			//cout << endl;
			c = 0;
			n = ++r;
			l++;
		}
	}
	c = 0; r = 1; n = 1;//三个数字复位
	int m = l;
	for (int i = 0; i < count; i++) {
		if (m == l-r+1) {
			for (int j = 0; j <= m; j++)
				cout << setw(2) << " ";
			m--;
		}
		cout << setw(3) << arraySavePrimes[i] << " ";
		c++;
		if (n <= c) {
			cout << endl;
			c = 0;
			n = ++r;
		}
	}
}