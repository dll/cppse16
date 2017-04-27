#include "CRTP.h"

using namespace crtp;
Circle::Circle(double r):radius(r){
	draw();
}
double Circle::getArea(){
	return (PI * radius * radius);
}
void Circle::draw(){
	std::cout << "»­Ô°¡£" << std::endl;
}
Rectangle::Rectangle(double l, double w):length(l),width(w) {
	draw();	
}

double Rectangle::getArea(){
	return (length * width);
}
void Rectangle::draw(){
	std::cout << "¾ØÐÎ¡£" << std::endl;
}

