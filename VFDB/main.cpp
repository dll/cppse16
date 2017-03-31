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
	TestvFunc();//�麯��
	TestonDraw();//���麯��
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
	cout <<  "ʹ�ö���:" ;s.doDraw ();
	Circle c2;
	Draw &rd = c2;
	cout <<  "\nʹ������:";rd. doDraw();
	Circle c3;
	Draw *pd = &c3;
	cout <<  "\nʹ��ָ��:"; pd -> doDraw () ;
}
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
void TestStaticCast(){
	Shape *pS=new Shape();
	Circle *pCtoS=static_cast<Circle*>(pS);//����ת��
	pCtoS->doDraw();
	
	Rectangle*pR=new Rectangle();
	Shape *pStoR=static_cast<Shape*>(pR);//����ת��
	pStoR->doDraw();
	
	Circle*pC=new Circle();
//	Triangle *pTtoR=static_cast<Triangle*>(pC);//����ת��,����ʧ�ܣ�
}
void TestDynamicCast(){
	Shape *pS=new Shape();
	Circle *pCtoS=dynamic_cast<Circle*>(pS);//����ת��,����ʧ�ܣ���
	if(pCtoS!=nullptr)
		pCtoS->doDraw();
	else
		throw bad_cast();
	
	Rectangle*pR=new Rectangle();
	Shape *pStoR=dynamic_cast<Shape*>(pR);//����ת�����ɹ���
	pStoR->doDraw();
	
	Circle*pC=new Circle();
	Triangle *pTtoC=dynamic_cast<Triangle*>(pC);//����ת��,����ʧ�ܣ���
	if(pTtoC!=nullptr)
		pTtoC->doDraw();
	else
		throw bad_cast();
}
