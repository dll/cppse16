#pragma once

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//����Employee��:�����µ���������
class Employee
{
private:
	string name;
	int age;
	char gender;
	unsigned workerID;
	double salary;
public://������Ա˵����
	Employee(){}
	Employee(std::string name,int age,char gender			 , unsigned workerID, double salary);                         	~Employee(){}	unsigned  	getWorkerID()const {return workerID;}	double 		getSalary()const{return salary;}
	string getName()const{return name;}
	int getAge()const{return age;}
	char getGender()const {return gender;}
	void Output();
	friend ostream& operator<<(ostream& out, const Employee& e);
};
