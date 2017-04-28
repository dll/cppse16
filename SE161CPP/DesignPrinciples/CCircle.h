#ifndef CCIRCLE_H
#define CCIRCLE_H
#include "Shape.h"
#include<iostream>
class CCircle : public Shape {
private:
	static double Pi;
	double radius;
public:
	CCircle(){}
	CCircle(double r);
	void draw();
	double getArea();
};

#endif

