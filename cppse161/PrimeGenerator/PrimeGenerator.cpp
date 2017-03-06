#include"stdafx.h"

#include"PrimeGenerator.h"

using namespace std;

PrimeGenerator::PrimeGenerator(int l, int u) :lowerNaturalNumber(l), upperNaturalNumber(u) {
	//...
}
void PrimeGenerator::getPrimeSequence() {
	cout << lowerNaturalNumber << "  ��  " << upperNaturalNumber << "֮�����������Ϊ��" << endl;

	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// ѭ������
		if (m == 1)			continue;		// ��·һ��ѭ���к���Ĳ���
		if (isPrime(m))
			cout << m << ", ";
	}
}

bool PrimeGenerator::isPrime(int number) {
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// ����number�ܱ�һ�����������Ͷ϶�����������
		}
	}
	return true;	// ���Խ�����û�б��κ����������϶�Ϊ����
}
