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
//	cout<<"请输入开始和结束的区间(非整数退出)："<<endl;
//	cin>>low>>up;
//	while(cin.fail()){
//		cout<<"输入数据类型错误！\n请重新输入"<<endl;
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
//		std::cerr << "不能打开primegenerator.data文件!\n";
//		system("pause");
//		exit(0);
//	}
//	while(fin>>low>>up){
//		PrimeGenerator pg(low,up);
//		pg.GetPrimeSequence();
//		if(!pg.SavePrimeSequence()){
//			cout<<"保存素数序列结果失败！"<<endl;
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

