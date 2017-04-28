#include "PillarCircle.h"

using namespace designpattern;
PillarCircle::PillarCircle(Circle b, double h):bottom(b),height(h) {
	draw();	
}

double PillarCircle::getVolume(){
	return (bottom.getArea() * height);
}
void PillarCircle::draw(){
	std::cout << "»­Ô°ÖùÌå¡£" << std::endl;
}
