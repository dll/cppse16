#ifndef POINT_H
#define POINT_H
#include<string>
using namespace std;

class Point {
private:
	string name;
protected:
public:
	Point(string name);
	void display();
	friend ostream & operator<<(ostream&out,const Point &p);//103
	~Point();
};

#endif

