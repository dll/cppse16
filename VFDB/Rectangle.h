#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<iostream>
#include"Shape.h"

class Rectangle:public Shape {
private:
protected:
public:
	Rectangle();
	~Rectangle();
	void doDraw ();
};

#endif

