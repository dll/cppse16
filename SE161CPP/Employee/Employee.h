#pragma once

#include<string>
#include<iostream>
#include"Person.h"

//定义Employee类:构造新的数据类型
class Employee:public Person
{
private:				// 访问控制关键字，私有成员说明符
	unsigned workerID;
	double salary;
public://公共成员说明符
	//Employee(){}
	Employee(std::string name,int age,char gender			 , unsigned workerID, double salary);                         	~Employee(){}	unsigned  	getWorkerID()const {return workerID;}	double 		getSalary()const{return salary;}
	void Output();
};
