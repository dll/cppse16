#include "Josephus.h"
#include <iostream>
#include<iomanip>
#include<windows.h>
using namespace std;list<int> JosephusProblem::josephusList;	// ��̬��Ա���ⲿ��ʼ��JosephusProblem::JosephusProblem(int ls,int st,int fr){	// ���캯��	listSize = ls;	steps = st;	first = fr;	for(int i = 1; i <= listSize; i ++)		josephusList.push_back(i);
	josephusSeq.clear();}void JosephusProblem::display(){				// ��ʾȫ��Ԫ��	list<int>::iterator it = josephusList.begin();	while(it != josephusList.end())		cout << *it++ <<"  ";	cout << endl;}int JosephusProblem::deleteElement() { 
	int result;	list<int>::iterator itor = josephusList.begin();  	while (josephusList.size() != 1) { 		int start = first; 		while ((start != steps )&& (josephusList.size() != 1)) {			itor++;			start++;			if (itor == josephusList.end()) {  				itor = josephusList.begin();  			} 		}		cout<<"P0"<< *itor << " ���㱨!\n";
		josephusSeq.push_back(*itor);		itor = josephusList.erase(itor); 		if (itor == josephusList.end()) { 			itor = josephusList.begin();  		} 
		Sleep(1000);	}  	cout << endl;
	josephusSeq.push_back(*(josephusList.begin()));
	cout<<"\nP0"<<*(josephusList.begin())<< " Ҫ�㱨!\n";
	result=	*(josephusList.begin());
	josephusList.erase(itor); 
	
	return result;} 
