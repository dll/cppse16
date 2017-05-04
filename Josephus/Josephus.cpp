#include "Josephus.h"
#include <iostream>
#include<iomanip>
using namespace std;list<int> JosephusProblem::josephusList;	// 静态成员的外部初始化JosephusProblem::JosephusProblem(int ls,int st,int fr){	// 构造函数	listSize = ls;	steps = st;	first = fr;	for(int i = 1; i <= listSize; i ++)		josephusList.push_back(i);
	josephusSeq.clear();}void JosephusProblem::display(){				// 显示全部元素	list<int>::iterator it = josephusList.begin();	while(it != josephusList.end())		cout << *it++ <<"  ";	cout << endl;}void JosephusProblem::deleteElement() { 	cout << "删除的数依次为：\n";	list<int>::iterator itor = josephusList.begin();  	while (josephusList.size() != 1) { 		int start = first; 		while ((start != steps )&& (josephusList.size() != 1)) {			itor++;			start++;			if (itor == josephusList.end()) {  				itor = josephusList.begin();  			} 		}		cout <<setw(2)<< *itor << "  ";
		josephusSeq.push_back(*itor);		itor = josephusList.erase(itor); 		if (itor == josephusList.end()) { 			itor = josephusList.begin();  		} 	}  	cout << endl;
	josephusSeq.push_back(*(josephusList.begin()));	cout<< endl << "最后剩余者："<< *(josephusList.begin())<<endl;  
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
		cout<<setw(2)<<i+1<<" 套";
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
				cout<<i+1<<"套 与 "<<j+1<<"套 重复"<<endl;
			}
	}
	if(flag)
		cout<<"无重复,抽卷成功!"<<endl;
	
}
void JosephusProblem::makeJosephusSeq() { 
	cout << "试卷的出题序号依次为：\n"<<setw(2)<<steps<<" "<<first<<endl;
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
