#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"

#ifdef DLL_IMPLEMENT 
#define DLL_API __declspec(dllexport) 
#else 
#define DLL_API __declspec(dllimport) 
#endif 
class DLL_API Manager : public Employee {
private:
protected:
public:
	Manager() {}
	void getPay();
};

#endif

