#include"PrimeGenerator.h"

using namespace std;

int main()
{
	cout << "\n单循环：" << endl;
	PrimeGenerator pg(1, 100);
	pg.getPrimeSequence();

	cout << "\n嵌套循环：" << endl;
	PrimeGenerator pg1(1, 100);
	pg1.getPrimeSequenceNestFor();
	pg1.printPrime3();

	try{
		cout << "\n\n友元类：" << endl;
		PrimeGenerator pg2(1, 100);
		pg2.getPrimeSequenceNestFor();//static int c;//有问题
		cout << "\n  友元类：静态数组存储并打印" << endl;
		savePrimeArray spa(pg2);
		spa.printSPrime();
		cout << "\n  友元类：动态数组存储并打印" << endl;
		savePrimeArray spa1(pg2, pg2.getCount());
		spa1.printDPrime();
	}	catch (bad_alloc const&) {		cerr << "存储溢出\n" << endl;;	}

	return 0;
}
