// CPPIOStream.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

class PrimeGenerator {

	int lowerNaturalNumber;
	int upperNaturalNumber;
	int count;//��������
	int *arraySavePrimes;//��������
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
	cout << lowerNaturalNumber << "  ��  " << upperNaturalNumber << "֮�����������Ϊ��" << endl;
	if (lowerNaturalNumber > upperNaturalNumber) {	// ����������뷴ʱ����
		int temp = lowerNaturalNumber;
		lowerNaturalNumber = upperNaturalNumber;
		upperNaturalNumber = temp;
	}
	arraySavePrimes = new int[upperNaturalNumber- lowerNaturalNumber];
	for (int m = lowerNaturalNumber; m <= upperNaturalNumber; m++) {	// ѭ������
		if (m < 2)
			continue;// ��·һ��ѭ���к���Ĳ���
		if (isPrime(m)) {
			cout << setw(3) << m << ", ";
			arraySavePrimes[count] = m;
			count++;
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
	c = 0; r = 1; n = 1;//�������ָ�λ
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
	c = 0; r = 1; n = 1;//�������ָ�λ
	int m = l;
	string saveprimefilename = "saveprime.txt";
	ofstream out(saveprimefilename);	// ��������������ļ�            	if (!out) {		cerr << "���ܴ�saveprime�ļ���\n";		exit(0);	}
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
	ifstream in(readprimefilename);	// �����������������ļ�  	if (!in) {		std::cerr << "���ܴ�readprime�ļ�!\n";		exit(0);	}
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
