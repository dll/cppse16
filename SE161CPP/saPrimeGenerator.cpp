#include "saPrimeGenerator.h"

using namespace std;

saPrimeGenerator::saPrimeGenerator(unsigned l, unsigned u):PrimeGenerator(l,u) {
//	cout<<"saconstruct"<<endl;
	for(unsigned i=GetLowNum(),j=0;i<=GetUpNum();i++){
		if(IsPrime(i)){
			StaticArrayPG[j++]=i;
//			cout<<StaticArrayPG[--j]<<", "; 
		}
	}
}

saPrimeGenerator::~saPrimeGenerator() {
	
}
void saPrimeGenerator::PrintPrime(){
//	cout<<"PrintPrime"<<endl;
	unsigned c=GetCount();
	cout<<c<<endl;
	for(unsigned i=1;i<=c;i++)
		cout<<StaticArrayPG[i-1]<<", ";
}
