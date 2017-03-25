#ifndef PEOPLE_H
#define PEOPLE_H
#include<string>
#include<iostream>

using namespace std;

class Person {
private:
	std::string name;
	int age;
	char gender;
protected:
public:
	Person(std::string, int, char);	
	void Output();
	std::string getName() const{return name;}
	int getAge() const {return age;}
	char getGender() const{return gender;}
};

#endif

