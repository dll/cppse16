#ifndef OCP_H
#define OCP_H
#include<iostream>
using namespace std;

namespace ocp{
	class Shape{// ΪԲ�;�����ӵĽӿڡ���������
	public:
		virtual  void draw()=0;
		virtual  double getArea()=0;
	};

	double const PI = 3.14159;
	class Circle : public Shape {
	private:
		double radius;
	protected:
	public:
		Circle(double);
		void draw ( );
		double getArea();
	};
	class Rectangle : public Shape {
	private:
		double length, width;
	protected:
	public:
		Rectangle(double,double);
		void draw ( );
		double getArea();
	};
}
#endif

