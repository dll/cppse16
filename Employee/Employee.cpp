#include"Employee.h"


#include "Person.h"
//\���з��ţ���ʾ7��8��9��10��11��һ��
					  unsigned workerID,\
					  double salary):Person (name, age, gender), \
					workerID (workerID), salary (salary) {}
void Employee::Output(){
	Person::Output ();
	cout<<"���ţ�"<<workerID<<endl;
	cout<<"нˮ��"<<salary<<endl;
}