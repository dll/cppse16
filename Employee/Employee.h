#pragma once

#include<string>
#include<iostream>
#include"Person.h"

//����Employee��:�����µ���������
class Employee:public Person
{
private:				// ���ʿ��ƹؼ��֣�˽�г�Ա˵����
	unsigned workerID;
	double salary;
public://������Ա˵����
	//Employee(){}
	Employee(std::string name,int age,char gender			 , unsigned workerID, double salary);                         	~Employee(){}	unsigned  	getWorkerID()const {return workerID;}	double 		getSalary()const{return salary;}
	void Output();
};
