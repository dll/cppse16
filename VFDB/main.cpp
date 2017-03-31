#include<iostream>
#include<cstdlib>
#include<typeinfo>

#include"Draw.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"

using namespace std;


void TestvFunc();
void TestonDraw();
void TestStaticCast();
void TestDynamicCast();

int main (int argc, char *argv[]) {
	TestvFunc();//虚函数
	TestonDraw();//纯虚函数
	TestStaticCast();
	try{
		TestDynamicCast();
	}catch(bad_cast){
		cout<<"dynamic_cast failed"<<endl;
		return 1;
	}catch(...){
		cout<<"Exception handling error."<<endl;
		return 1;
	}
	
	return 0;
}

void TestvFunc(){
	Circle c1;
	//Draw dr = c1;
	Shape s=c1;
	cout <<  "使用对象:" ;s.doDraw ();
	Circle c2;
	Draw &rd = c2;
	cout <<  "\n使用引用:";rd. doDraw();
	Circle c3;
	Draw *pd = &c3;
	cout <<  "\n使用指针:"; pd -> doDraw () ;
}
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
void TestStaticCast(){
	Shape *pS=new Shape();
	Circle *pCtoS=static_cast<Circle*>(pS);//下行转换
	pCtoS->doDraw();
	
	Rectangle*pR=new Rectangle();
	Shape *pStoR=static_cast<Shape*>(pR);//上行转换
	pStoR->doDraw();
	
	Circle*pC=new Circle();
//	Triangle *pTtoR=static_cast<Triangle*>(pC);//交叉转换,编译失败！
}
void TestDynamicCast(){
	Shape *pS=new Shape();
	Circle *pCtoS=dynamic_cast<Circle*>(pS);//下行转换,运行失败！！
	if(pCtoS!=nullptr)
		pCtoS->doDraw();
	else
		throw bad_cast();
	
	Rectangle*pR=new Rectangle();
	Shape *pStoR=dynamic_cast<Shape*>(pR);//上行转换，成功！
	pStoR->doDraw();
	
	Circle*pC=new Circle();
	Triangle *pTtoC=dynamic_cast<Triangle*>(pC);//交叉转换,运行失败！！
	if(pTtoC!=nullptr)
		pTtoC->doDraw();
	else
		throw bad_cast();
}
