#include<iostream>
#include"Draw.h"
#include"Circle.h"
#include"Rectangle.h"

using namespace std;

int main (int argc, char *argv[]) {
	Circle c1;	Draw dr = c1;	cout <<  "ʹ�ö���:" ;dr.doDraw ();	Circle c2;	Draw &rd = c2;	cout <<  "\nʹ������:";rd. doDraw();	Circle c3;	Draw *pd = &c3;	cout <<  "\nʹ��ָ��:"; pd -> doDraw () ;	
	return 0;
}

