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
		PokerGame(int,int);// ���������ÿ��������ʼ��
		void shuffle ();
		void cardsSort();
		void sendCards ();
		void pokerDisplay();// ������ʽ�˿��еĸ�����
};

#endif
