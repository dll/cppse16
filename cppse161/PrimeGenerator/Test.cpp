#include"PrimeGenerator.h"

using namespace std;

int main()
{
	cout << "\n��ѭ����" << endl;
	PrimeGenerator pg(1, 100);
	pg.getPrimeSequence();

	cout << "\nǶ��ѭ����" << endl;
	PrimeGenerator pg1(1, 1000);
	pg1.getPrimeSequenceNestFor();

	return 0;
}
