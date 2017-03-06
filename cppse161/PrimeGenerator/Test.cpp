#include"PrimeGenerator.h"

using namespace std;

int main()
{
	cout << "\nµ¥Ñ­»·£º" << endl;
	PrimeGenerator pg(1, 100);
	pg.getPrimeSequence();

	cout << "\nÇ¶Ì×Ñ­»·£º" << endl;
	PrimeGenerator pg1(1, 1000);
	pg1.getPrimeSequenceNestFor();

	return 0;
}
