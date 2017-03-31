#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include "Draw.h"
using namespace std;

class Shape : public Draw {
private:
protected:
public:
	Shape();
	~Shape();
	void doDraw ( );
};

#endif

