#include "PokerGame.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	PokerGame pokergame1(4,12);
	pokergame1.sendCards();
	return 0;
}
