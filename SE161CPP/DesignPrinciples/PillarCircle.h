#ifndef PILLARCIRCLE_H
#define PILLARCIRCLE_H

#include "Circle.h"
using namespace  designpattern;
class PillarCircle {
	private:		Circle bottom;		double height;	public:		PillarCircle (Circle b, double h);		double getVolume();
		void draw();
};

#endif

