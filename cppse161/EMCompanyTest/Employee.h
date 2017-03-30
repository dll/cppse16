#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>

#ifdef DLL_IMPLEMENT 
#define DLL_API __declspec(dllexport) 
#else 
#define DLL_API __declspec(dllimport) 
#endif 
class DLL_API Employee {
private:
protected:
public:
	Employee() {}
	virtual void getPay();//获得工资
};

#endif

