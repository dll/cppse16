#ifndef POKERGAME_H
#define POKERGAME_H
#include <vector>
using namespace std;
class PokerGame {
	private:
		static vector<int> poker;//静态变量，存放扑克
		int playerNumber;//玩家数
		int eachCards;//每个玩家的牌数
		vector<vector<int>> inHand;//每局牌况
	public:
		PokerGame(int p=4,int e=12);//默认值
		void shuffle ();//洗牌
		void cardsSort();//排序
		void sendCards ();//发牌
		void pokerDisplay();//亮牌
		void pokerBomb();//炸牌
};

#endif
