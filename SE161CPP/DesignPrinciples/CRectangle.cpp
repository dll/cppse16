#include "CRectangle.h"
#include "CCircle.h"
CRectangle::CRectangle(double l, double w):length(l),width(w) {
	draw();	
}

double CRectangle::getArea(){
	return (length * width);
}
void CRectangle::draw(){
	std::cout << "¾ØÐÎ¡£" << std::endl;
}
