#include"Employee.h"

//\���з��ţ���ʾ7��8��9��10��11��һ��Employee :: Employee (string name, int age, char gender, \
					  unsigned workerID,\
					  double salary):name(name), age(age), gender(gender), \
					workerID (workerID), salary (salary) {}
ostream& operator << (ostream& out, const Employee& e){
	out << "������" <<e.getName () << endl;
	out << "���䣺" <<e.getAge () << endl;
	out << "�Ա�" <<e.getGender () << endl;
	out<<"���ţ�"<<e.workerID<<endl;
	out<<"нˮ��"<<e.salary<<endl;
	return out;
}
