#ifndef COMPANY_H
#define COMPANY_H
#include"Employee.h"

class Company {
private:
protected:
public:
	void payroll(Employee &re);//������������reference Employee
	void payroll(Employee *pe);//���ο�����pointer Employee
};

#endif

