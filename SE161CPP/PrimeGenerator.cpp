#include "PrimeGenerator.h"
#include<fstream>
#include<typeinfo>
using namespace std;

PrimeGenerator::PrimeGenerator(unsigned l, unsigned u):lownum(l),upnum(u) {
	count=0;
	LowUpNumber(*this);
	for (int m = lownum; m <= upnum; m++) {	
		if (m < 2)
			continue;
		if (IsPrime(m)) 
			count++;
	}
}

PrimeGenerator::~PrimeGenerator() {
	
}

bool PrimeGenerator::IsPrime(unsigned number) {
	if(number==1)return false;
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// ����number�ܱ�һ�����������Ͷ϶�����������
		}
	}
	return true;	// ���Խ�����û�б��κ����������϶�Ϊ����
}

void PrimeGenerator::GetPrimeSequence() {
	cout << lownum << "  ��  " << upnum << "֮�����������Ϊ��" << endl;
	for (int m = lownum; m <= upnum; m++) {	// ѭ������
		if (m < 2)
			continue;// ��·һ��ѭ���к���Ĳ���
		if (IsPrime(m)) {
			cout << m << ", ";
			//count++;
		}
	}
	cin.ignore(4,'\n');
	cout<<endl;
}

bool PrimeGenerator::SavePrimeSequence() {
	ofstream fout("primesequence.result",ios::app);
	if(!fout)
		return false;
	fout << lownum << " " << upnum<<endl;
	for (int m = lownum; m <= upnum; m++) {	// ѭ������
		if (m < 2)
			continue;// ��·һ��ѭ���к���Ĳ���
		if (IsPrime(m)) {
			fout << m << ", ";
		}
	}
	fout<<endl;
	fout.close();
	return true;
}

//��Ԫ������Ҫ����������
void LowUpNumber(PrimeGenerator&pg){
	if(pg.lownum>pg.upnum){
		unsigned temp=pg.lownum;
		pg.lownum=pg.upnum;
		pg.upnum=temp;
	}
}
