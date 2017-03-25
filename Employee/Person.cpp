#include "Person.h"
using namespace std;

Person::Person(std::string n, int a, char g) {
		name=n;age=a;gender=g;
}

void Person::Output(){
	cout << "姓名：" << getName () << endl;	cout << "年龄：" << getAge () << endl;	cout << "性别：" << getGender () << endl;
}
