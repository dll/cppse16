#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
class Circle {private:	static double Pi;	double radius;public:
	Circle(){}	Circle(double r);	void draw();	double getArea();};

namespace RingCircle{
	double const PI = 3.14159;  // ����һ��double�ͳ���PI
	class Circle {	private:		double radius;	public:		Circle (double r):radius (r){}		double calcPerimeter ()  {      // ����Բ�ܳ�			return 2 * PI * radius;		}		double calcArea ()  {              // ����Բ���			return PI * radius * radius;		}	};
	
	class Ring  {	private:		Circle inner,outer; // ����Circle��������	public:		Ring (double inr = 0,double our = 0):inner (inr),outer (our){
//				if(inr>our){
//					inner=Circle(our);
//					outer=Circle(inr);
//				}
		}		double   calcPerimeter () {   // ���㻷�����ܳ�			return outer.calcPerimeter () + inner.calcPerimeter ();		}		double  calcArea ()  { // ���㻷�����			return outer.calcArea () - inner.calcArea ();		}	};
}#endif

