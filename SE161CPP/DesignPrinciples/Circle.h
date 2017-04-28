#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
namespace designpattern{
	double const PI = 3.14159;  // 定义一个double型常量PI
	class Circle {
	private:
		static double Pi;
		double radius;
	public:
		Circle(){}
		Circle(double r);
		void draw();
		double getArea(){
			return (PI * radius * radius);
		}
	};
}
#endif

