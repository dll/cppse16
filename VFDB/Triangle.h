#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include"Draw.h"

class Triangle:public Draw {
private:
protected:
public:
	Triangle();
	~Triangle();
	void doDraw ();
};

#endif

