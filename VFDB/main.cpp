#include<iostream>
#include<cstdlib>

#include"Draw.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"


using namespace std;
void TestvFunc();
void TestonDraw();

int main (int argc, char *argv[]) {
//	TestvFunc();
	TestonDraw();
	
	
	return 0;
}

//void TestvFunc(){
//	Circle c1;
//	Draw dr = c1;
//	cout <<  "ʹ�ö���:" ;dr.doDraw ();
//	Circle c2;
//	Draw &rd = c2;
//	cout <<  "\nʹ������:";rd. doDraw();
//	Circle c3;
//	Draw *pd = &c3;
//	cout <<  "\nʹ��ָ��:"; pd -> doDraw () ;
//}
void TestonDraw(){
	int choice;
	Circle c;
	Rectangle r;
	Triangle t;	Draw *pd = NULL;	cout << "1����Բ��2�������Σ�3���������Ρ���ѡ��";	cin >> choice;	switch (choice){		case 1 : 			pd = &c;			break;		case 2 : 						pd = &r;			break;		case 3 : 						pd = &t;			break;
		default:
			cout<<"����ѡ��1��2��3����"<<endl;
			system("pause");
			exit(0);	}	pd -> doDraw();
}
