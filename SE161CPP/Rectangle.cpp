#include "Rectangle.h"

Rectangle::Rectangle(double l, double w):length(l),width(w) {
	draw();	
}

double Rectangle::getArea(){
	return (length * width);
}
void Rectangle::draw(){
	std::cout << "���Ρ�" << std::endl;
}
