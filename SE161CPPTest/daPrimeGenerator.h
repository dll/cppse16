#ifndef DAPRIMEGENERATOR_H
#define DAPRIMEGENERATOR_H
#include "PrimeGenerator.h"

class daPrimeGenerator : public PrimeGenerator {
private:
	unsigned *dynamicArrayPG;
protected:
public:
	friend class PrimerManager;
	daPrimeGenerator(unsigned, unsigned);
	~daPrimeGenerator();
	void PrintPrime();
};

#endif

