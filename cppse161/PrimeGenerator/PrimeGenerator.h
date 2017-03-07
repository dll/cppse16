#pragma once
/*
������prime number���ֳ������������޸�����������Ϊ�ڴ���1����Ȼ���У�
����1�����������ⲻ������������������Ϊ������1����������
2��������Ψһż��
*/
#include<iostream>
#include<iomanip>
#include<new> 

const int MAXPRIME = 256;


class PrimeGenerator {

	int lowerNaturalNumber;
	int upperNaturalNumber;
	int count;//��������
	int arraySavePrimes[MAXPRIME];//��������
public:
	friend class savePrimeArray;

	PrimeGenerator(int l, int u);
	void getPrimeSequence();
	void getPrimeSequenceNestFor();
	bool isPrime(int number);
	void printPrime1(int number);
	void printPrime2(int number);
	void printPrime3();
	int getCount() { return count; }
};

class savePrimeArray {
	int count;
	int sArray[MAXPRIME];
	int *dArray;

public:
	savePrimeArray(const PrimeGenerator& pg) {
		dArray = NULL;
		count = pg.count;
		if (count > MAXPRIME){
			std::cout << "̫���������ռ�������" << std::endl;
			exit(0);
		}
		for (int i = 0; i < count; i++)
			sArray[i] = pg.arraySavePrimes[i];
	}
	savePrimeArray(const PrimeGenerator& pg, int c):count(c) {
		dArray = new int[count];
		if (!dArray)
			throw - 1;
		for (int i = 0; i < count; i++)
			dArray[i] = pg.arraySavePrimes[i];
	}
	void printSPrime() {
		for (int i = 0; i < count; i++) {
			std::cout << sArray[i] << ", ";
		}
	}
	void printDPrime() {
		for (int i = 0; i < count; i++) {
			std::cout << dArray[i] << ", ";
		}
	}
	~savePrimeArray() {
		if(dArray!=NULL)
			delete[] dArray;
	}
};
