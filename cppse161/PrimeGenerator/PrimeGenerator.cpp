#include<iostream>

#include"PrimeGenerator.h"

using namespace std;

PrimeGenerator::PrimeGenerator(int l, int u)
	:lowerNaturalNumber(l), upperNaturalNumber(u), count(0) {}

void PrimeGenerator::getPrimeSequence() {
	cout << lowerNaturalNumber << "  ��  " << upperNaturalNumber << "֮�����������Ϊ��" << endl;
	if (lowerNaturalNumber > upperNaturalNumber) {	// ����������뷴ʱ����
		int temp = lowerNaturalNumber;
		lowerNaturalNumber = upperNaturalNumber;
		upperNaturalNumber = temp;
	}
	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// ѭ������
		if (m < 2)
			continue;// ��·һ��ѭ���к���Ĳ���
		if (isPrime(m)) {
			//cout << m << ", ";
			count++;
			printPrime(1, m);
		}
	}
	cout << "\n���� " << count << " ������" << endl;
}

bool PrimeGenerator::isPrime(int number) {
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// ����number�ܱ�һ�����������Ͷ϶�����������
		}
	}
	return true;	// ���Խ�����û�б��κ����������϶�Ϊ����
}

void PrimeGenerator::getPrimeSequenceNestFor() {
	cout << lowerNaturalNumber << "  ��  " << upperNaturalNumber << "֮�����������Ϊ��" << endl;
	if (lowerNaturalNumber > upperNaturalNumber) {	// ����������뷴ʱ����
		int temp = lowerNaturalNumber;
		lowerNaturalNumber = upperNaturalNumber;
		upperNaturalNumber = temp;
	}
	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// ѭ������
		if (m < 2)
			continue;// ��·һ��ѭ���к���Ĳ���
					 //if (isPrime(m))
					 //	cout << m << ", ";
		bool flag = true;
		for (int n = 2; n < m; n++) {
			flag = true;
			if (m % n == 0) {
				flag = false;	// �ܱ�һ�����������Ͷ϶�����������
				break;
			}
		}
		if (flag == true) {
			//std::cout<< m<<", ";
			count++;
			printPrime(2, m);
		}
	}
	cout << "\n���� " << count << " ������" << endl;
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
