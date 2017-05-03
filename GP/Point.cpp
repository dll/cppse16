#include "Point.h"
#include<iostream>
using namespace std;

Point::Point(string name):name(name) {
	cout<<"����Point��"<<name<<endl;
}

Point::~Point() {
	cout<<"����Point��"<<name<<endl;
}

void Point::display(){
	cout<<name<<endl;
}

ostream & operator<<(ostream&out,const Point &p){
	out<<p.name;
	return out;
}
