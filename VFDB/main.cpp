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
//	cout <<  "使用对象:" ;dr.doDraw ();
//	Circle c2;
//	Draw &rd = c2;
//	cout <<  "\n使用引用:";rd. doDraw();
//	Circle c3;
//	Draw *pd = &c3;
//	cout <<  "\n使用指针:"; pd -> doDraw () ;
//}
void TestonDraw(){
	int choice;
	Circle c;
	Rectangle r;
	Triangle t;	Draw *pd = NULL;	cout << "1——圆；2——矩形；3——三角形。请选择：";	cin >> choice;	switch (choice){		case 1 : 			pd = &c;			break;		case 2 : 						pd = &r;			break;		case 3 : 						pd = &t;			break;
		default:
			cout<<"输入选择1，2，3错误！"<<endl;
			system("pause");
			exit(0);	}	pd -> doDraw();
}
