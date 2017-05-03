#pragma once

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//定义Employee类:构造新的数据类型
class Employee
{
private:
	string name;
	int age;
	char gender;
	unsigned workerID;
	double salary;
public://公共成员说明符
	Employee(){}
	Employee(std::string name,int age,char gender			 , unsigned workerID, double salary);                         	~Employee(){}	unsigned  	getWorkerID()const {return workerID;}	double 		getSalary()const{return salary;}
	string getName()const{return name;}
	int getAge()const{return age;}
	char getGender()const {return gender;}
	void Output();
	friend ostream& operator<<(ostream& out, const Employee& e);
};
