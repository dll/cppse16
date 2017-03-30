#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Employee.h"

#ifdef DLL_IMPLEMENT 
#define DLL_API __declspec(dllexport) 
#else 
#define DLL_API __declspec(dllimport) 
#endif 
class DLL_API Programmer : public Employee {
private:
protected:
public:
	Programmer() {}
	void getPay();
	void getBonus();
};

#endif

