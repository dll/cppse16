#ifndef DRAWFACTORY_H
#define DRAWFACTORY_H
#include "Draw.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include<cstdlib>
class DrawFactory {
			default:cout<<"������1,2,3��"<<endl;exit(0);
	virtual Draw* MakeDrawer ()= 0;
		return new Triangle();
#endif
