#ifndef SHAPE_H
#define SHAPE_H

#include"ICalcArea.h"
#include"IDrawShape.h"

//class Shape{// 为圆和矩形添加的接口——抽象类//	public:
//		virtual  void draw()=0;//		virtual  double getArea()=0;//};

class Shape:public ICalcArea,public IDrawShape{// 为圆和矩形添加的接口——抽象类
//public:
//	virtual  void draw()=0;
//	virtual  double getArea()=0;
};

#endif
