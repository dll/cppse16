#include "Pillar.h"

Pillar::Pillar(Circle c, double h):Circle(c),height(h){
	draw();	
}
double Pillar::getVolume(){
	return (getArea() * height);
}
void Pillar::draw(){
	std::cout << "��԰���塣" << std::endl;
}
