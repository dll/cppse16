#pragma once
/*
������prime number���ֳ������������޸�����������Ϊ�ڴ���1����Ȼ���У�
����1�����������ⲻ������������������Ϊ������1����������
2��������Ψһż��
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
