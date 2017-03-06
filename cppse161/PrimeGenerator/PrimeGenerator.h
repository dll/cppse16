#pragma once
/*
质数（prime number）又称素数，有无限个。质数定义为在大于1的自然数中，
除了1和它本身以外不再有其他因数的数称为质数。1不是质数，
2是质数且唯一偶数
*/
#include<iostream>
#include<iomanip>

class PrimeGenerator {
	int lowerNaturalNumber;
	int upperNaturalNumber;
	int count;
public:
	PrimeGenerator(int l, int u);
	void getPrimeSequence();
	void getPrimeSequenceNestFor();
	bool isPrime(int number);
	void printPrime(int style, int number);
};
