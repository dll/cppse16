#include<iostream>

#include"PrimeGenerator.h"

using namespace std;

PrimeGenerator::PrimeGenerator(int l, int u)
	:lowerNaturalNumber(l), upperNaturalNumber(u), count(0){}

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
			arraySavePrimes[count] = m;
			count++;
			printPrime1( m);
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
			arraySavePrimes[count] = m;
			count++;
			printPrime2(m);
		}
	}
	cout << "\n���� " << count << " ������" << endl;
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
	c = 0; r = 1; n = 1;//�������ָ�λ
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