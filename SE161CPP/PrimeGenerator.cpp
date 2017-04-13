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
			return false;// 发现number能被一个数整除，就断定它不是素数
		}
	}
	return true;	// 测试结束还没有被任何数整除，断定为素数
}

void PrimeGenerator::GetPrimeSequence() {
	cout << lownum << "  到  " << upnum << "之间的素数序列为：" << endl;
	for (int m = lownum; m <= upnum; m++) {	// 循环控制
		if (m < 2)
			continue;// 短路一次循环中后面的部分
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
	for (int m = lownum; m <= upnum; m++) {	// 循环控制
		if (m < 2)
			continue;// 短路一次循环中后面的部分
		if (IsPrime(m)) {
			fout << m << ", ";
		}
	}
	fout<<endl;
	fout.close();
	return true;
}

//有元函数不要加类作用域
void LowUpNumber(PrimeGenerator&pg){
	if(pg.lownum>pg.upnum){
		unsigned temp=pg.lownum;
		pg.lownum=pg.upnum;
		pg.upnum=temp;
	}
}
