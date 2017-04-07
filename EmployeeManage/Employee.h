#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class  Employee {
private:
protected:
public:
	Employee() {}
	virtual void getPay()=0;//获得工资
};

#endif

/*
-Wl,--output-def,EmployeeManage.def,--out-implib,EmployeeManage.lib
*/
