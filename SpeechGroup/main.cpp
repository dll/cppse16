#include<iostream>
#include"Josephus.h"
#include <fstream>
#include <cassert>
using namespace std;
void showGroup(string fname, int r){
	string sg;
	ifstream ifile(fname,ios::in);
	ofstream ofile("speechgroup.txt",ios::app);
	if(!ifile)exit(0);
	for(int i=0;i<r;i++){
		ifile>>sg;
	}
	cout<<sg<<endl;
	ofile<<sg<<endl;
	ofile.close();
	ifile.close();
	system("speechgroup.txt");
}

int main (int argc, char *argv[]) {
	
	ofstream ofile("speechgroup.txt",ios::out);
	ofile.close();
	srand(time(NULL));
	const int t=7;
	int s=rand()%t+1;
	JosephusProblem jose(t,s,1);
	cout << "随机抽取G1项目组\n";
	int r=jose.deleteElement();	
	showGroup("projectgroup1.txt",r);
	system("pause");
	s=rand()%t+1;
	JosephusProblem jose1(t,s,1);
	cout << "随机抽取G2项目组\n";
	r=jose1.deleteElement();	
	showGroup("projectgroup2.txt",r);
	
	return 0;
}

