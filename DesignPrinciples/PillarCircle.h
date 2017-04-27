#ifndef PILLARCIRCLE_H
#define PILLARCIRCLE_H

#include "Circle.h"

class PillarCircle {
	private:		Circle bottom;		double height;	public:		PillarCircle (Circle b, double h);		double getVolume();
		void draw();
};

#endif

