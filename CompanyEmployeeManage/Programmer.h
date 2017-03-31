#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Employee.h"

class Programmer : public Employee {
private:
protected:
public:
	int getPay();
	int getBonus();//基薪+奖金，接口是公开，提供给开发人员的
};

#endif

