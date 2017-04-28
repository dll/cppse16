#ifndef PILLAR_H
#define PILLAR_H
#include "Circle.h"
using namespace designpattern;

class Pillar : public Circle {private:	double height;public:	Pillar (Circle r, double h);	double getVolume();
	void draw();};
#endif

