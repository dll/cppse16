#ifndef CPILLAR_H
#define CPILLAR_H
#include "Shape.h"
#include "CCircle.h"

class CPillar {
private:
	Shape& bottom;
	double height;
public:
	CPillar (Shape& b, double h);
	double getVolume();
	void draw();
};
#endif

