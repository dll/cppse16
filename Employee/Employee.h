#pragma once

#include<string>
#include<iostream>
#include"Person.h"

//����Employee��:�����µ���������
class Employee:public Person
{
private:				// ���ʿ��ƹؼ��֣�˽�г�Ա˵����
//	std::string emplName;		// ְԱ����
//	int 	emplAge;		// ְԱ����
//	char 	emplGender;		// ְԱ�Ա�
//	float 	emplBaseSalary;	// ְԱ��������
	unsigned int workerID;
	double salary;
public://������Ա˵����
//	Employee(std::string name, int age, char sex, float baseSalary);	//���캯�����������ĺ���������ͬ��
//	void printEmployee(void);		// ��ӡְԱ��Ա����
	Employee(std::string name,int age,char gender			 , unsigned int workerID, double salary);                         	~Employee(){}	unsigned  	getWorkerID()const {return workerID;}	double 		getSalary()const{return salary;}
};
