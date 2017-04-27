#ifndef CRTP_H
#define CRTP_H
#include<iostream>
using namespace std;

//奇异递归模板模式(CRTP)
namespace crtp{
	template<typename T>
	class Shape{// 为圆和矩形添加的接口——抽象类
	public:
		void draw();
		void calcArea() {
			std::cout<<static_cast<T*>(this)->getArea()<<endl;
		}
		double getArea(){}
	};
	
	double const PI = 3.14159;
	class Circle : public Shape<Circle> {
	private:
		double radius;
	protected:
	public:
		Circle(double);
		void draw ( );
		double getArea();
		void calcArea() {
			std::cout<<static_cast<Circle*>(this)->getArea()<<endl;
		}
	};
	class Rectangle : public Shape<Rectangle> {
	private:
		double length, width;
	protected:
	public:
		Rectangle(double,double);
		void draw ( );
		double getArea();
		void calcArea() {
			std::cout<<static_cast<Rectangle*>(this)->getArea()<<endl;
		}
	};
}
#endif

