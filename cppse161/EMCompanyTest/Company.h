#ifndef COMPANY_H
#define COMPANY_H
#include"Employee.h"

class Company {
private:
protected:
public:
	void payroll(Employee &re);
	void payroll(Employee *pe);//二次开发
};

#endif

