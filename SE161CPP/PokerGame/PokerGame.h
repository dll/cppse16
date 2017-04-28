#ifndef POKERGAME_H
#define POKERGAME_H
#include <vector>
using namespace std;
class PokerGame {
	private:
		static vector<int> poker;
		int playerNumber;
		int eachCards;
	public:
		PokerGame(int,int);// 用玩家数、每人牌数初始化
		void shuffle ();
		void cardsSort();
		void sendCards ();
		void pokerDisplay();// 依次显式扑克中的各张牌
};

#endif
