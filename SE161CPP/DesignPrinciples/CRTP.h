#ifndef CRTP_H
#define CRTP_H
#include<iostream>
using namespace std;

//����ݹ�ģ��ģʽ(CRTP)
namespace crtp{
	template<typename T>
	class Shape{// ΪԲ�;�����ӵĽӿڡ���������
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

