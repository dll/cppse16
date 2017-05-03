#ifndef POKERGAME_H
#define POKERGAME_H
#include <vector>
using namespace std;
class PokerGame {
	private:
		static vector<int> poker;//��̬����������˿�
		int playerNumber;//�����
		int eachCards;//ÿ����ҵ�����
		vector<vector<int>> inHand;//ÿ���ƿ�
	public:
		PokerGame(int p=4,int e=12);//Ĭ��ֵ
		void shuffle ();//ϴ��
		void cardsSort();//����
		void sendCards ();//����
		void pokerDisplay();//����
		void pokerBomb();//ը��
};

#endif
