#ifndef COMPANY_H
#define COMPANY_H
#include"Employee.h"

class Company {
private:
protected:
public:
	void payroll(Employee &re);//引用作参数，reference Employee
	void payroll(Employee *pe);//二次开发，pointer Employee
};

#endif

