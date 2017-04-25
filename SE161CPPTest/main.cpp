#include<iostream>
#include<fstream>
#include<cstdlib>
#include"PrimeGenerator.h"
#include"PrimerManager.h"
#include"saPrimeGenerator.h"
#include"daPrimeGenerator.h"
#include"max.h"
#include"ArrayTmp.hpp"
#include "BoundArrayTmp.hpp"
#include<ctime>
#include"StackTmp.hpp"

#include"Employee.h"
#include<fstream>
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
	
//	daPrimeGenerator daPG(100,1);
//	daPG.PrintPrime();
//	
//	PrimerManager pm;
//	pm.SavePrimerToFile(daPG);
	
//	cout<<myMax(10,8)<<endl;
//	cout<<myMax(10,18)<<endl;
//	cout<<myMax('a', 'b')<<endl;// myMax<char>//	cout<<myMax(56, 'b')<<endl;// error: no matching function for call to 'myMax(int, char)'
//	cout<<myMax(10,18,3)<<endl;
	
//	ArrayTmp <int>  IntAry( 5 ) ;//	for (int i = 0; i < 5; i ++ )  IntAry.set ( i, i ) ;
//	IntAry.display();//	cout << "Integer Array : \n" ;//	for (int i = 0; i < 5; i ++ )  cout << IntAry.get(i) << endl ;//	//	ArrayTmp <double> DouAry( 5 ) ;//	for (int i = 0; i < 5; i ++ )  DouAry.set ( i, (i+1)*0.35 ) ;//	cout << "Double Array : \n" ;//	for (int i = 0; i < 5; i ++ )  cout << DouAry.get(i) << '\t' ;//	cout<<endl;//	
//	ArrayTmp <int>  IntAry1( 5 ) ;
//	IntAry1=IntAry;
//	cout << "ArrayTmp IntAry1: \n" ;
//	for (int i = 0; i < 8; i ++ )  cout << IntAry1.get(i) << endl ;
	
//	BoundArrayTmp <int>  IntAry2(0,4) ;
//	for (int i = 0; i < 5; i ++ )  IntAry2.set ( i, i ) ;
//	cout<<"First Element of BoundArrayTmp IntAry2:"<<IntAry2.begin()<<endl;
//	cout<<"Last Element of BoundArrayTmp IntAry2:"<<IntAry2.end()<<endl;
//	cout << "BoundArrayTmp IntAry2: \n" ;
//	IntAry2.display();
//	IntAry2.deleteElement(3);//
//	IntAry2.display();
//	IntAry2.resize(5);
//	IntAry2.set(4,44);
//	IntAry2.insertElement(2,11);
//	IntAry2.display();
//	for (int i = 0; i < 8; i ++ )  
//		cout << IntAry2.get(i) << endl ;
//	
//	BoundArrayTmp <int>  IntAry3(1,5) ;
//	BoundArrayTmp <int>  IntAry4(0,40) ;
//	IntAry3=IntAry2;
//	IntAry4=IntAry2;
//	cout << "BoundArrayTmp IntAry4: \n" ;
//	for (int i = 0; i < 8; i ++ )  cout << IntAry4.get(i) << endl ;
	
//	srand( (unsigned)time( NULL ) );
//	IntAry2.deleteElement(rand()%IntAry2.size);
//	IntAry2.display();
//
//	BoundArrayTmp <int>  IntAry5(0,9) ;
//	cout << "Random BoundArrayTmp IntAry5: \n" ;
//	for (int i = 0; i < 10; i ++ )  
//		IntAry5.set(i,rand()%100) ;
//	IntAry5.display();
//	IntAry5.selectSort();
//	IntAry5.display();
	
	StackTmp<int> intStackTmp;
	intStackTmp.init();
	intStackTmp.push(66);
	intStackTmp.display();
	intStackTmp.pop();
	intStackTmp.display();
	intStackTmp.push(1);intStackTmp.push(2);intStackTmp.push(3);
	intStackTmp.display();//1,2,3
	intStackTmp.pop();
	intStackTmp.display();//2,3   1,2后进先出
	
	StackTmp<char> charStackTmp;
	charStackTmp.init();
	charStackTmp.push('A');
	charStackTmp.display();
	charStackTmp.pop();
	charStackTmp.display();
	charStackTmp.push('A');charStackTmp.push('B');charStackTmp.push('C');
	charStackTmp.display();//1,2,3
	charStackTmp.pop();
	charStackTmp.display();//2,3   1,2后进先出
	string n;
	int a;
	char g;
	unsigned w;
	double s;
//	//读文件流
//	ifstream ifs("Employee.data");
//	while(ifs>>n>>a>>g>>w>>s){
//		Employee empn(n,a,g,w,s);
//		empn.Output();
//	}
//	ifs.close();
	
	StackTmp<Employee> EmployeeStackTmp;//类属
	EmployeeStackTmp.init();
	ifstream eifs("Employee.data");
	while(eifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		EmployeeStackTmp.push(empn);
	}
	EmployeeStackTmp.display();
	eifs.close();
	
	return 0;
}

