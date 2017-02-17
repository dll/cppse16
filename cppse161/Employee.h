#pragma once

#include<string>
#include<iostream>

//定义Employee类:构造新的数据类型
class Employee
{
private:				// 访问控制关键字，私有成员说明符
	std::string 	emplName;		// 职员姓名
	int 	emplAge;		// 职员年龄
	char 	emplGender;		// 职员性别
	float 	emplBaseSalary;	// 职员基本工资

public://公共成员说明符
	//Employee(std::string name, int age, char sex, float baseSalary);	//构造函数：构造对象的函数，与类同名
	//void printEmployee(void);		// 打印职员成员函数
	Employee();	 	// 无参构造函数
	Employee(std::string name, int age, char sex);	  // 部分参数构造函数
	Employee(std::string name, int age, char sex, float baseSalary); // 完全参数构造函数
	Employee(const Employee& employee);	          //  复制构造函数
	void   printEmployee();

	~Employee();
};