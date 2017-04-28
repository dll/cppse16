#ifndef DRAWFACTORY_H
#define DRAWFACTORY_H
#include "Draw.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include<cstdlib>
class DrawFactory {public:	static Draw* getInstance (int choice) {		Draw* pd = nullptr;		switch (choice) {			case 1:pd = new Circle ();	 break;					case 2:pd = new Rectangle ();break; 				case 3:pd = new Triangle (); break; 
			default:cout<<"ÇëÊäÈë1,2,3£¡"<<endl;exit(0);		}		return pd;	}
	virtual Draw* MakeDrawer ()= 0;};class CirFactory  : public DrawFactory {	public: Draw* MakeDrawer () {		return new Circle ();	}};class RecFactory : public DrawFactory {	public: Draw* MakeDrawer () {		return new Rectangle ();	}};class TriFactory : public DrawFactory {	public: Draw* MakeDrawer () {		//return &(Triangle ());
		return new Triangle();	}};
#endif

