#include"PrimeGenerator.h"

using namespace std;

int main()
{
	cout << "\n��ѭ����" << endl;
	PrimeGenerator pg(1, 100);
	pg.getPrimeSequence();

	cout << "\nǶ��ѭ����" << endl;
	PrimeGenerator pg1(1, 100);
	pg1.getPrimeSequenceNestFor();
	pg1.printPrime3();

	try{
		cout << "\n\n��Ԫ�ࣺ" << endl;
		PrimeGenerator pg2(1, 100);
		pg2.getPrimeSequenceNestFor();//static int c;//������
		cout << "\n  ��Ԫ�ࣺ��̬����洢����ӡ" << endl;
		savePrimeArray spa(pg2);
		spa.printSPrime();
		cout << "\n  ��Ԫ�ࣺ��̬����洢����ӡ" << endl;
		savePrimeArray spa1(pg2, pg2.getCount());
		spa1.printDPrime();
	}	catch (bad_alloc const&) {		cerr << "�洢���\n" << endl;;	}

	return 0;
}
