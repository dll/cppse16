#include"Employee.h"

/*
void  Employee::printEmployee(void) {
	std::cout << this->emplName << ", " << this->emplAge << ","
		<< this->emplGender << ", " << this->emplBaseSalary
		<< std::endl;
}

Employee::Employee(std::string name, int age, char sex, float baseSalary) {
	this->emplName = name;
	this->emplAge = age;
	this->emplGender = sex;
	this->emplBaseSalary = baseSalary;
}*/

Employee::Employee() {
	std::cout << "ִ���޲ι��캯����\n";
};

Employee::Employee(std::string name, int age, char sex) {
	std::cout << "ִ�в��ֲ������캯����\n";
	this->emplName = name;
	this->emplAge = age;
	this->emplGender = sex;
}
Employee::Employee(std::string name, int age, char sex, float baseSalary) {
	std::cout << "ִ��ȫ���������캯����\n";
	this->emplName = name;
	this->emplAge = age;
	this->emplGender = sex;
	this->emplBaseSalary = baseSalary;
}
Employee::Employee(const Employee& employee) {
	std::cout << "ִ�и��ƹ��캯����\n";
	this->emplName = employee.emplName;
	this->emplAge = employee.emplAge;
	this->emplGender = employee.emplGender;
	this->emplBaseSalary = employee.emplBaseSalary;
}
void Employee::printEmployee() {
	std::cout << this->emplName << "," << this->emplAge << ","
		<< this->emplGender << "," << this->emplBaseSalary
		<< std::endl;
}

Employee::~Employee() {
	//....
}