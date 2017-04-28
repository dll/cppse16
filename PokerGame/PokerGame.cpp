#include "PokerGame.h"
#include <iostream>
#include <cstdlib>	#include <ctime>
#include <algorithm>
#include<fstream>

using namespace std;vector<int> PokerGame::poker = {
	101,102,103,104,105,106,107,108,109,110,111,112,113,	201,202,203,204,205,206,207,208,209,210,211,212,213,	301,302,303,304,305,306,307,308,309,310,311,312,313,	401,402,403,404,405,406,407,408,409,410,411,412,413,	501,502};
PokerGame::PokerGame(int pn, int ec){	playerNumber = pn;	eachCards = ec;}void PokerGame::pokerDisplay(){	// 依次显示扑克牌	cout << "扑克中各牌依次为：\n";
	int i=1; 	for(vector<int>::iterator it = poker.begin();it != poker.end();it ++){		cout << *it << "  ";
		if(i++%13==0)
			cout<<endl;
	}	cout << endl;}
void PokerGame::shuffle () {	srand((int)time(0)); 	// 用时间作为随机数种子	vector<int>::iterator it,iend,rdm;	iend = poker.end();	for ( it = poker.begin(); it != iend; ++it ) {		rdm = rand() % (iend - it) + it;		swap(*it,*rdm);	}}void PokerGame::cardsSort () {	sort (poker.begin(),poker.end());	
}
void PokerGame::sendCards (){
	vector<int> veachCards;	vector<vector<int>>inHand(playerNumber,veachCards);	vector<vector<int>>::iterator iti;	vector<int>::iterator itj;	for(int i=0; i !=  eachCards; i ++) { 	  			for( iti = inHand.begin(); iti != inHand.end(); iti ++) { 	 			iti->push_back(poker.back());			poker.pop_back();		}	}	cout << "各位玩家手中的牌：\n";	for( iti = inHand.begin(); iti != inHand.end(); iti ++) { 		for(itj = iti -> begin(); itj != iti->end(); itj ++)   			cout << *itj << "  ";		cout << endl; 	}	cout << "\n底牌为：\n";	for( itj = poker.begin(); itj != poker.end(); itj ++) { 	// 外层迭代  		cout << *itj << "  ";	} 	cout << endl; 
	
	ofstream ofin("Poker.txt");
	ofin << "各位玩家手中的牌：\n";
	for( iti = inHand.begin(); iti != inHand.end(); iti ++) { 
		for(itj = iti -> begin(); itj != iti->end(); itj ++)   
			ofin << *itj << "  ";
		ofin << endl; 
	}
	ofin << "\n底牌为：\n";
	for( itj = poker.begin(); itj != poker.end(); itj ++) { 	// 外层迭代  
		ofin << *itj << "  ";
	} 
	ofin << endl; 
	ofin.close();
	system("Poker.txt");} 