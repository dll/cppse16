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
	Employee(){}
	Employee(std::string name,int age,char gender
	void Output();
	friend ostream& operator<<(ostream& out, const Employee& e);
};