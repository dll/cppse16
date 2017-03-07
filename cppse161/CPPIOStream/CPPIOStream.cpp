// CPPIOStream.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

class PrimeGenerator {

	int lowerNaturalNumber;
	int upperNaturalNumber;
	int count;//素数个数
	int *arraySavePrimes;//保存素数
public:
	PrimeGenerator(int l, int u);
	void getPrimeSequence();
	bool isPrime(int number);
	void printPrime();
	void savePrime();
};

PrimeGenerator::PrimeGenerator(int l, int u)
	:lowerNaturalNumber(l), upperNaturalNumber(u), count(0) {
	arraySavePrimes = nullptr;
}

void PrimeGenerator::getPrimeSequence() {
	cout << lowerNaturalNumber << "  到  " << upperNaturalNumber << "之间的素数序列为：" << endl;
	if (lowerNaturalNumber > upperNaturalNumber) {	// 区间界限输入反时交换
		int temp = lowerNaturalNumber;
		lowerNaturalNumber = upperNaturalNumber;
		upperNaturalNumber = temp;
	}
	arraySavePrimes = new int[upperNaturalNumber- lowerNaturalNumber];
	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// 循环控制
		if (m < 2)
			continue;// 短路一次循环中后面的部分
		if (isPrime(m)) {
			cout << setw(3) << m << ", ";
			arraySavePrimes[count] = m;
			count++;
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

void PrimeGenerator::printPrime() {
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
		if (m == l - r + 1) {
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
	cout << endl;
}
void PrimeGenerator::savePrime() {
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
	string saveprimefilename = "saveprime.txt";
	ofstream out(saveprimefilename);	// 创建输出流并打开文件            	if (!out) {		cerr << "不能打开saveprime文件！\n";		exit(0);	}
	for (int i = 0; i < count; i++) {
		if (m == l - r + 1) {
			for (int j = 0; j <= m; j++)
				out << setw(2) << " ";
			m--;
		}
		out << setw(3) << arraySavePrimes[i] << " ";
		c++;
		if (n <= c) {
			out << endl;
			c = 0;
			n = ++r;
		}
	}
	out << endl;
	out.close();
	system(saveprimefilename.c_str());
}

int main(){
	string readprimefilename = "readprime.txt";
	ifstream in(readprimefilename);	// 创建输入流并打开账文件  	if (!in) {		std::cerr << "不能打开readprime文件!\n";		exit(0);	}
	int l, u;
	in >> l >> u;
	in.close();
	PrimeGenerator pg(l, u);
	pg.getPrimeSequence();
	pg.printPrime();

	pg.savePrime();
	system(readprimefilename.c_str());

    return 0;
}
