#include "PillarCircle.h"

PillarCircle::PillarCircle(Circle b, double h):bottom(b),height(h) {
	draw();	
}

double PillarCircle::getVolume(){
	return (bottom.getArea() * height);
}
void PillarCircle::draw(){
	std::cout << "��԰���塣" << std::endl;
}
