#pragma once
class PrimeGenerator {	int lowerNaturalNumber;	int upperNaturalNumber;public:	PrimeGenerator(int l, int u);	void getPrimeSequence();	bool isPrime(int);};