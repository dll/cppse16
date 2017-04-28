#include "Pillar.h"

using namespace designpattern;
Pillar::Pillar(Circle c, double h):Circle(c),height(h){
	draw();	
}
double Pillar::getVolume(){
	return (getArea() * height);
}
void Pillar::draw(){
	std::cout << "»­Ô°ÖùÌå¡£" << std::endl;
}
