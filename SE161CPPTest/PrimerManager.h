#ifndef PRIMERMANAGER_H
#define PRIMERMANAGER_H
#include "PrimeGenerator.h"
class PrimeGenerator;
class PrimerManager {
private:
protected:
public:
	
	PrimerManager();
	~PrimerManager();
	void SavePrimerToFile(PrimeGenerator &pg);
};

#endif
