#include "DtoOther.h"
#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
	DtoOther dto1(32767,16); 
	DtoOther dto4(32767,12); 
	dto4.convert();
	DtoOther dto5(32767,4); 
	dto5.convert();
	return 0;
}
