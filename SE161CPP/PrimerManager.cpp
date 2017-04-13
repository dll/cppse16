#include "PrimerManager.h"
#include"PrimeGenerator.h"
#include"saPrimeGenerator.h"
#include"daPrimeGenerator.h"

#include<fstream>
#include<typeinfo>
using namespace std;

PrimerManager::PrimerManager() {
	
}

PrimerManager::~PrimerManager() {
	
}


void PrimerManager::SavePrimerToFile(PrimeGenerator &pg){
	ofstream fout("prime.save",ios::out);
	if(typeid(pg)==typeid(saPrimeGenerator)){
		saPrimeGenerator &saPG=static_cast<saPrimeGenerator&>(pg);
		for(int i=0;i<saPG.GetCount();i++)
			fout<<saPG.StaticArrayPG[i]<<" ";
	}
	else{
		daPrimeGenerator &daPG=static_cast<daPrimeGenerator&>(pg);
		for(int i=0;i<daPG.GetCount();i++)
			fout<<daPG.dynamicArrayPG[i]<<" ";
	}
	fout.close();
}
