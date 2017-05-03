// CPPIOStream.cpp : �������̨Ӧ�ó������ڵ㡣

#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class PrimeGenerator {
	
	int lowernum;
	int uppernum;
	int count;//��������
	int *arraySavePrimes;//��������
public:
	PrimeGenerator(int l, int u);
	void getPrimeSequence();
	bool isPrime(int number);
	void printPrime();
	void savePrime();
};

PrimeGenerator::PrimeGenerator(int l, int u)
	:lowernum(l), uppernum(u), count(0) {
	arraySavePrimes = 0;
}

void PrimeGenerator::getPrimeSequence() {
	cout << lowernum << "  " << uppernum << "֮����������У�" ;
	if (lowernum > uppernum) {	// ����������뷴ʱ����
		int temp = lowernum;
		lowernum = uppernum;
		uppernum = temp;
	}
	arraySavePrimes = new int[uppernum- lowernum];
	for (int m = lowernum; m <= uppernum; m++) {	// ѭ������
		if (m < 2)
			continue;// ��·һ��ѭ���к���Ĳ���
		if (isPrime(m)) {
			arraySavePrimes[count] = m;
			count++;
		}
	}
	cout << count << " ��������" << endl;
}

bool inline PrimeGenerator::isPrime(int number) {
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// ����number�ܱ�һ�����������Ͷ϶�����������
		}
	}
	return true;	// ���Խ�����û�б��κ����������϶�Ϊ����
}

void PrimeGenerator::printPrime() {
	int col = 0;//col
	int row = 1;//row
	int nrow = 0;//row num
	
	int level = 0;//level
	
	for (int i = 0; i < count; i++) {
		col++;
		if (nrow <= col) {
			col = 0;
			nrow = ++row;
			level++;
		}
	}
	col = 0; row= 1; nrow = 1;//�������ָ�λ
	int m = level;
	for (int i = 0; i < count; i++) {
		if (m == level - row + 1) {
			for (int j = 0; j <= m; j++)
				cout << setw(2) << " ";
			m--;
		}
		cout << setw(3) << arraySavePrimes[i] << " ";
		col++;
		if (nrow <= col) {
			cout << endl;
			col = 0;
			nrow = ++row;
		}
	}
	cout << endl;
}
void PrimeGenerator::savePrime() {
	string saveprimefilename = "saveprime.txt";
	ofstream out(saveprimefilename.c_str());	// ��������������ļ�            	if (!out) {		cerr << "���ܴ�saveprime�ļ���\n";		exit(0);	}
	out<<lowernum<<" "<<uppernum<<endl;
	for (int i = 0; i < count; i++) {
		out << setw(3) << arraySavePrimes[i] << " ";
	}
	out << endl;
	out.close();
	system(saveprimefilename.c_str());
}

int main(int argc, char *argv[]){
	
	string readprimefilename = "readprimelowup.txt";
	ifstream in(readprimefilename.c_str());	// �����������������ļ�  	if (!in) {		std::cerr << "���ܴ�readprime�ļ�!\n";		exit(0);	}
	int low, up;
	while(in >> low >> up){
		PrimeGenerator pg(low, up);
		pg.getPrimeSequence();
		pg.printPrime();
		
		pg.savePrime();
	}
	in.close();
	system(readprimefilename.c_str());
	
	return 0;
}
