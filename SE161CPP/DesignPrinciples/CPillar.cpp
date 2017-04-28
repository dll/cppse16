#include "CPillar.h"

CPillar::CPillar(Shape& b, double h):bottom(b),height(h){
	draw();
}double CPillar::getVolume(){
	return (bottom.getArea() * height);
}void CPillar::draw(){
	std::cout << "»­Ô²Öù¡£" << std::endl;
}