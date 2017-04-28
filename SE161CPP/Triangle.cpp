#include "Triangle.h"
#include <cmath>
void Triangle::draw(){
	std::cout << "Èý½ÇÐÎ¡£" << std::endl;
}
double Triangle::getArea(){
	double c=(aSide+bSide+cSide)/2;
	double s=sqrt(c*(c-aSide)*(c-bSide)*(c-cSide));
	return s;
}
