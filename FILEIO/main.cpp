// CPPIOStream.cpp : 定义控制台应用程序的入口点。

#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class PrimeGenerator {
	
	int lowernum;
	int uppernum;
	int count;//素数个数
	int *arraySavePrimes;//保存素数
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
	cout << lowernum << "  " << uppernum << "之间的素数共有：" ;
	if (lowernum > uppernum) {	// 区间界限输入反时交换
		int temp = lowernum;
		lowernum = uppernum;
		uppernum = temp;
	}
	arraySavePrimes = new int[uppernum- lowernum];
	for (int m = lowernum; m <= uppernum; m++) {	// 循环控制
		if (m < 2)
			continue;// 短路一次循环中后面的部分
		if (isPrime(m)) {
			arraySavePrimes[count] = m;
			count++;
		}
	}
	cout << count << " 个素数。" << endl;
}

bool inline PrimeGenerator::isPrime(int number) {
	for (int m = 2; m < number; m++) {
		if (number % m == 0) {
			return false;// 发现number能被一个数整除，就断定它不是素数
		}
	}
	return true;	// 测试结束还没有被任何数整除，断定为素数
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
	col = 0; row= 1; nrow = 1;//三个数字复位
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
	ofstream out(saveprimefilename.c_str());	// 创建输出流并打开文件            	if (!out) {		cerr << "不能打开saveprime文件！\n";		exit(0);	}
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
	ifstream in(readprimefilename.c_str());	// 创建输入流并打开账文件  	if (!in) {		std::cerr << "不能打开readprime文件!\n";		exit(0);	}
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
