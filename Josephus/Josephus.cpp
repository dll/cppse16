#include "Josephus.h"
#include <iostream>
#include<iomanip>
using namespace std;list<int> JosephusProblem::josephusList;	// ��̬��Ա���ⲿ��ʼ��JosephusProblem::JosephusProblem(int ls,int st,int fr){	// ���캯��	listSize = ls;	steps = st;	first = fr;	for(int i = 1; i <= listSize; i ++)		josephusList.push_back(i);
	josephusSeq.clear();}void JosephusProblem::display(){				// ��ʾȫ��Ԫ��	list<int>::iterator it = josephusList.begin();	while(it != josephusList.end())		cout << *it++ <<"  ";	cout << endl;}void JosephusProblem::deleteElement() { 	cout << "ɾ����������Ϊ��\n";	list<int>::iterator itor = josephusList.begin();  	while (josephusList.size() != 1) { 		int start = first; 		while ((start != steps )&& (josephusList.size() != 1)) {			itor++;			start++;			if (itor == josephusList.end()) {  				itor = josephusList.begin();  			} 		}		cout <<setw(2)<< *itor << "  ";
		josephusSeq.push_back(*itor);		itor = josephusList.erase(itor); 		if (itor == josephusList.end()) { 			itor = josephusList.begin();  		} 	}  	cout << endl;
	josephusSeq.push_back(*(josephusList.begin()));	cout<< endl << "���ʣ���ߣ�"<< *(josephusList.begin())<<endl;  
	josephusList.erase(itor); } void JosephusProblem::saveJosephusSeq(){
	ofstream ofout("josephusSeq.txt",ios::app);
	for(vector<int>::iterator it=josephusSeq.begin();
		it!=josephusSeq.end();it++)
		ofout<<setw(2)<<*it<<" ";
	ofout<<endl;
	ofout.close();
}

void makeTestPapers(vector<JosephusProblem*> testPapers, int tps, int ls){
	int st,fr;
	ofstream ofout("testPapers.txt");
	srand((int)time(0));
	for(int i=0;i<tps;i++){		
		st= rand() % tps + 1;
		fr= rand() % ls + 1;
		testPapers.push_back(new JosephusProblem(ls,st,fr));
		cout<<setw(2)<<i+1<<" ��";
		ofout<<setw(2)<<i+1<<": ";
		testPapers[i]->makeJosephusSeq();
		for(vector<int>::iterator it=testPapers[i]->josephusSeq.begin();
		it!=testPapers[i]->josephusSeq.end();it++)
			ofout<<setw(2)<<*it<<" ";
		ofout<<endl;
	}
	ofout.close();
	bool flag=true;
	for(int i=0; i<tps; i++){
		for(int j=0; j<tps&&i!=j; j++)
			if(testPapers[i]->josephusSeq== testPapers[j]->josephusSeq){
				flag=false;
				cout<<i+1<<"�� �� "<<j+1<<"�� �ظ�"<<endl;
			}
	}
	if(flag)
		cout<<"���ظ�,���ɹ�!"<<endl;
	
}
void JosephusProblem::makeJosephusSeq() { 
	cout << "�Ծ�ĳ����������Ϊ��\n"<<setw(2)<<steps<<" "<<first<<endl;
	list<int>::iterator itor = josephusList.begin(); 
	int start = first; 
	while(start!=0){
		start--;
		itor++;
		if (itor == josephusList.end()) {  
			itor = josephusList.begin();  
		} 
	}
	while (josephusList.size() != 1) { 
		int count = 1; 
		while ((count != steps )&& (josephusList.size() != 1)) {
			itor++;
			count++;
			if (itor == josephusList.end()) {  
				itor = josephusList.begin();  
			} 
		}
		cout<<setw(2) << *itor << "  ";
		josephusSeq.push_back(*itor);
		itor = josephusList.erase(itor); 
		if (itor == josephusList.end()) { 
			itor = josephusList.begin();  
		} 
	}  
	josephusSeq.push_back(*(josephusList.begin()));
	cout<<setw(2)<< *(josephusList.begin())<<endl; 
	josephusList.erase(itor); 
} 
