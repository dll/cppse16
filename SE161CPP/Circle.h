#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
#include "Draw.h"
class Circle:public Draw{private:	static double Pi;	double radius;public:
	Circle(){}	Circle(double r);	void draw();	double getArea();};
#endif

