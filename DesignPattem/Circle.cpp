#include "Circle.h"

double Circle::Pi = 3.1415926;

Circle::Circle(double r):radius(r){
	draw();
}

double Circle::getArea(){
	return (Pi * radius * radius);
}
void Circle::draw(){
	std::cout << "»­Ô°¡£" << std::endl;
}