#include<iostream>
#include<fstream>
#include<cstdlib>
#include"PrimeGenerator.h"
#include"PrimerManager.h"
#include"saPrimeGenerator.h"
#include"daPrimeGenerator.h"

using namespace std;

int main (int argc, char *argv[]) {
	unsigned low, up;
//	cout<<"�����뿪ʼ�ͽ���������(�������˳�)��"<<endl;
//	cin>>low>>up;
//	while(cin.fail()){
//		cout<<"�����������ʹ���\n����������"<<endl;
//		cin.clear();
//		cin.ignore(1024,'\n');
//		cin>>low>>up;
//	}
//	PrimeGenerator pg(low,up);
//	pg.GetPrimeSequence();

//	string pglowup = "primegenerator.data";
//	ifstream fin(pglowup.c_str());
//	ifstream fin;
//	fin.open(pglowup.c_str(),ios::in);
//	if (!fin) {
//		std::cerr << "���ܴ�primegenerator.data�ļ�!\n";
//		system("pause");
//		exit(0);
//	}
//	while(fin>>low>>up){
//		PrimeGenerator pg(low,up);
//		pg.GetPrimeSequence();
//		if(!pg.SavePrimeSequence()){
//			cout<<"�����������н��ʧ�ܣ�"<<endl;
//			system("pause");
//			exit(0);
//		}
//
//	}
//	fin.close();
//	saPrimeGenerator saPG(100,1);
//	saPG.PrintPrime();
	
	daPrimeGenerator daPG(100,1);
	daPG.PrintPrime();
	
	PrimerManager pm;
	pm.SavePrimerToFile(daPG);
	
	return 0;
}

