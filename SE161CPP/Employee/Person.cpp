#include "Person.h"
using namespace std;

Person::Person(string n, int a, char g) {
		name=n;age=a;gender=g;
}

void Person::Output(){
	cout << "������" << getName () << endl;
}