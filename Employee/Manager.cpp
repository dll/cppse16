#include "Manager.h"

Manager::Manager (string name, int age, char gender, \
				  unsigned int workerID,double salary,\
		string post):Employee(name, age, gender,workerID,salary),\
		post(post){}


Manager::~Manager() {
	
}

void Manager::Output(){
	Employee::Output();
	cout<<"Ö°Î»£º"<<post<<endl;
}

