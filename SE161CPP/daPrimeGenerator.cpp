#include "daPrimeGenerator.h"
using namespace std;

daPrimeGenerator::daPrimeGenerator(unsigned l, unsigned u):PrimeGenerator(l,u) {
	dynamicArrayPG = new unsigned[GetCount()];
	for(unsigned i=GetLowNum(),j=0;i<=GetUpNum();i++){
		if(IsPrime(i)){
			dynamicArrayPG[j++]=i;
		}
	}
}

daPrimeGenerator::~daPrimeGenerator() {
	delete []dynamicArrayPG;
}

void daPrimeGenerator::PrintPrime(){
	unsigned c=GetCount();
	cout<<c<<endl;
	for(unsigned i=1;i<=c;i++)
		cout<<dynamicArrayPG[i-1]<<", ";
}
