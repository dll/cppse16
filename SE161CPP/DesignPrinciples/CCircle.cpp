#include "CCircle.h"

double CCircle::Pi = 3.1415926;

CCircle::CCircle(double r):radius(r){
	draw();
}

double CCircle::getArea(){
	return (Pi * radius * radius);
}
void CCircle::draw(){
	std::cout << "»­Ô°¡£" << std::endl;
}
