#ifndef SHAPE_H
#define SHAPE_H

#include"ICalcArea.h"
#include"IDrawShape.h"

//class Shape{// ΪԲ�;�����ӵĽӿڡ���������//	public:
//		virtual  void draw()=0;//		virtual  double getArea()=0;//};

class Shape:public ICalcArea,public IDrawShape{// ΪԲ�;�����ӵĽӿڡ���������
//public:
//	virtual  void draw()=0;
//	virtual  double getArea()=0;
};

#endif
