#ifndef CRECTANGLE_H
#define CRECTANGLE_H
#include "Shape.h"

class CRectangle : public Shape {
private:
	double length,width;
protected:
public:
	CRectangle(double, double);
	void draw ( );
	double getArea();
};

#endif

