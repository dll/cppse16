#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include"Shape.h"

class Triangle:public Shape {
private:
protected:
public:
	Triangle();
	~Triangle();
	void doDraw ();
};

#endif

