#include"stdafx.h"

#include"PrimeGenerator.h"

using namespace std;

PrimeGenerator::PrimeGenerator(int l, int u) :lowerNaturalNumber(l), upperNaturalNumber(u) {
	//...
}
void PrimeGenerator::getPrimeSequence() {
	cout << lowerNaturalNumber << "  到  " << upperNaturalNumber << "之间的素数序列为：" << endl;

	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// 循环控制
		if (m == 1)			continue;		// 短路一次循环中后面的部分
		if (isPrime(m))
			cout << m << ", ";
	}
}

bool PrimeGenerator::isPrime(int number) {
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// 发现number能被一个数整除，就断定它不是素数
		}
	}
	return true;	// 测试结束还没有被任何数整除，断定为素数
}
