#ifndef SAPRIMEGENERATOR_H
#define SAPRIMEGENERATOR_H
#include "PrimeGenerator.h"

const unsigned COUNT=256;

class saPrimeGenerator : public PrimeGenerator {
private:
	unsigned StaticArrayPG[COUNT];
protected:
public:
	friend class PrimerManager;
	saPrimeGenerator(unsigned l, unsigned u);
	~saPrimeGenerator();
	void PrintPrime();
};

#endif

