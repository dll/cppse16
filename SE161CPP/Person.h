#ifndef PEOPLE_H
#define PEOPLE_H
#include<string>
#include<iostream>

using namespace std;

class Person {
private:
	string name;
	int age;
	char gender;
protected:
public:
	Person(){}
	Person(string, int, char);	
	void Output();
	string getName() const{return name;}//inline内联函数，性能好
	int getAge() const {return age;}
	char getGender() const{return gender;}
};

#endif

