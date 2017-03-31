#include "stdafx.h"
#include <typeinfo>  

#include "Company.h"

#include"include\\Employee.h"//在类库中
#include "include\\Programmer.h"

using namespace std;

void Company::payroll(Employee &re){
	//老的计算工资的方法
	//re.getPay();
	try{
		Programmer &rp=dynamic_cast<Programmer&>(re);
		rp.getBonus();//发给程序员的工资
	}catch(bad_cast){
		re.getPay();//发给经理的工资	
	}
}
void Company::payroll(Employee *pe){
	if (Programmer *pp = dynamic_cast<Programmer*>(pe))
		pp->getBonus();
	else{
		pe->getPay();	
	}
}
