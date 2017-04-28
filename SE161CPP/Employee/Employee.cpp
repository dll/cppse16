#include"Employee.h"


#include "Person.h"#include "employee.h"
//\续行符号，表示7、8、9、10、11是一行Employee :: Employee (string name, int age, char gender, \
					  unsigned workerID,\
					  double salary):Person (name, age, gender), \
					workerID (workerID), salary (salary) {}
void Employee::Output(){
	Person::Output ();
	cout<<"工号："<<workerID<<endl;
	cout<<"薪水："<<salary<<endl;
}
