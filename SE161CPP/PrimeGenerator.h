#ifndef PRIMEGENERATOR_H
#define PRIMEGENERATOR_H
#include<iostream>
#include "PrimerManager.h"

class PrimeGenerator {
private:
	unsigned lownum;
	unsigned upnum;
	unsigned count;
protected:
public:
	friend void LowUpNumber(PrimeGenerator&pg);
	friend class PrimerManager;
	
	PrimeGenerator(unsigned l, unsigned u);
	~PrimeGenerator();
	bool IsPrime(unsigned);
	void GetPrimeSequence();
	bool SavePrimeSequence();
	
	unsigned GetLowNum(){return lownum;}
	unsigned GetUpNum(){return upnum;}
	unsigned GetCount(){return count;}
};
#endif

