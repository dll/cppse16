#pragma once
/*
质数（prime number）又称素数，有无限个。质数定义为在大于1的自然数中，
除了1和它本身以外不再有其他因数的数称为质数。1不是质数，
2是质数且唯一偶数
*/
#include<iostream>
#include<iomanip>
#include<new> 

const int MAXPRIME = 256;


class PrimeGenerator {

	int lowerNaturalNumber;
	int upperNaturalNumber;
	int count;//素数个数
	int arraySavePrimes[MAXPRIME];//保存素数
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
			std::cout << "太多素数，空间已满！" << std::endl;
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
