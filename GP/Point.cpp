#include "Point.h"
#include<iostream>
using namespace std;

Point::Point(string name):name(name) {
	cout<<"创建Point点"<<name<<endl;
}

Point::~Point() {
	cout<<"销毁Point点"<<name<<endl;
}

void Point::display(){
	cout<<name<<endl;
}

ostream & operator<<(ostream&out,const Point &p){
	out<<p.name;
	return out;
}
