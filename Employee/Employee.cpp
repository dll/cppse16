#include"Employee.h"

//void  Employee::printEmployee(void) {
//	std::cout << this->emplName << ", " << this->emplAge << ","
//		<< this->emplGender << ", " << this->emplBaseSalary
//		<< std::endl;
//}
//
//Employee::Employee(std::string name, int age, char sex, float baseSalary) {
//	this->emplName = name;
//	this->emplAge = age;
//	this->emplGender = sex;
//	this->emplBaseSalary = baseSalary;
//}

#include "Person.h"#include "employee.h"Employee :: Employee (string name, int age, char gender, unsigned int workerID,\
					  double salary):Person (name, age, gender), \
					workerID (workerID), salary (salary) {}
