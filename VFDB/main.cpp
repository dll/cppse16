#include<iostream>
#include"Draw.h"
#include"Circle.h"
#include"Rectangle.h"

using namespace std;

int main (int argc, char *argv[]) {
	Circle c1;	Draw dr = c1;	cout <<  "使用对象:" ;dr.doDraw ();	Circle c2;	Draw &rd = c2;	cout <<  "\n使用引用:";rd. doDraw();	Circle c3;	Draw *pd = &c3;	cout <<  "\n使用指针:"; pd -> doDraw () ;	
	return 0;
}

