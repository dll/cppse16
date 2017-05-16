#include "myArray.h"

myArray::myArray(int sz) {
	this->size=sz;
	element=new int[size];
}

myArray::~myArray() {
	delete []element;
}
int & myArray::operator[](int index){
	return element[index];
}
void myArray::set(int index, int value){
	element[index]=value;
}
int myArray::get(int index){
	return element[index];
}
