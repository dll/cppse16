#include "PokerGame.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	PokerGame pokergame1(4,12);	cout << "ϴ��ǰ���˿������У�\n";	pokergame1.pokerDisplay();	pokergame1.shuffle ();	cout << "ϴ�ƺ���˿������У�\n";	pokergame1.pokerDisplay();
	pokergame1.sendCards();
	return 0;
}

