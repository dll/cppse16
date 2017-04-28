#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Draw.h"

class Rectangle:public Draw{
private:
	double length,width;
protected:
public:
	Rectangle(){}
	Rectangle(double, double);
	void draw ( );
	double getArea();
};

#endif

