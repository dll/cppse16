#include "PokerGame.h"
#include <iostream>
#include <cstdlib>	
#include <algorithm>
#include<fstream>

using namespace std;
	101,102,103,104,105,106,107,108,109,110,111,112,113,
};

	inHand= vector<vector<int>>(playerNumber,vector<int>(0));
	int i=1; 
		if(i++%13==0)
			cout<<endl;
	}
void PokerGame::shuffle () {
	cardsSort();
}
void PokerGame::sendCards (){
	//��Ļ��ʾ	���ļ�����
	ofstream fout("Poker.txt");
	fout << "��λ������е��ƣ�\n";
			fout << *itj << "  ";
		}
		fout << endl;
	fout << "\n����Ϊ��\n";
		fout << *itj << "  ";
	fout << endl; 
	fout.close();
void PokerGame::pokerBomb (){
	vector<vector<int>>::iterator iti;
	vector<int>::iterator itj;
	vector<int> bomb;
	vector<int>::iterator itb;
	vector<int>::iterator itb4;
	int bombNum=0;
	//��Ļ��ʾ���ļ�����
	cout << "\n��λ������е�ը����\n";
	ofstream fout("Poker.txt", ios::app);//׷��ģʽ�����������ӵ��ļ�β��
	fout << "\n��λ������е�ը����\n";
	for( iti = inHand.begin(); iti != inHand.end(); iti ++) { 
		cout<<*iti -> begin()<<" ***: ";
		fout<<*iti -> begin()<<" ***: ";
		bombNum=0;
		for(itj = iti -> begin(); itj != iti->end(); itj ++){   
			bomb.push_back(*itj);
			for(itb=++itj;itb !=iti->end();itb++){
				if(bomb.front()%100==*itb%100 && *itb!=501&&*itb!=502)
					bomb.push_back(*itb);
			}
			if(bomb.size()==4){
				for(itb4=bomb.begin();itb4!=bomb.end();itb4++){
					cout<<*itb4<<" ";
					fout<<*itb4<<" ";
				}
				bombNum++;
			}
			bomb.clear();
		}
		cout<<bombNum<<endl;
		fout<<bombNum<<endl;
	}
	
	fout << endl; 
	fout.close();
//	system("Poker.txt");
} 