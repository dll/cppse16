#include "PokerGame.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	PokerGame pokergame1(4,12);	cout << "洗牌前的扑克牌排列：\n";	pokergame1.pokerDisplay();	pokergame1.shuffle ();	cout << "洗牌后的扑克牌排列：\n";	pokergame1.pokerDisplay();
	pokergame1.sendCards();
	return 0;
}

