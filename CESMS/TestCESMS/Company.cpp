#include "stdafx.h"
#include <typeinfo>  

#include "Company.h"

#include"include\\Employee.h"//�������
#include "include\\Programmer.h"

using namespace std;

void Company::payroll(Employee &re){
	//�ϵļ��㹤�ʵķ���
	//re.getPay();
	try{
		Programmer &rp=dynamic_cast<Programmer&>(re);
		rp.getBonus();//��������Ա�Ĺ���
	}catch(bad_cast){
		re.getPay();//��������Ĺ���	
	}
}
void Company::payroll(Employee *pe){
	if (Programmer *pp = dynamic_cast<Programmer*>(pe))
		pp->getBonus();
	else{
		pe->getPay();	
	}
}
