#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Draw.h"

class Triangle : public Draw {
private:
	double aSide,bSide,cSide;
protected:
public:
	Triangle(){}
	Triangle(double, double, double);
	void draw ( );
	double getArea();
};

#endif

