#include "PokerGame.h"
#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
	PokerGame pokergame(4,12);	cout << "洗牌前的扑克牌排列：\n";	pokergame.pokerDisplay();	pokergame.shuffle ();	cout << "洗牌后的扑克牌排列：\n";	pokergame.pokerDisplay();
	pokergame.sendCards();
	pokergame.pokerBomb();
	return 0;
}

/*
vector:一维，二维向量
iterator
sort,swap
rand,srand
洗牌，发牌算法设计和实现:伪代码，编码
*/
