#include "PokerGame.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	PokerGame pokergame(4,12);
	pokergame.sendCards();
	pokergame.pokerBomb();
	return 0;
}

/*
vector:һά����ά����
iterator
sort,swap
rand,srand
ϴ�ƣ������㷨��ƺ�ʵ��:α���룬����
*/