#include"Employee.h"

//\续行符号，表示7、8、9、10、11是一行Employee :: Employee (string name, int age, char gender, \
					  unsigned workerID,\
					  double salary):name(name), age(age), gender(gender), \
					workerID (workerID), salary (salary) {}
ostream& operator << (ostream& out, const Employee& e){
	out << "姓名：" <<e.getName () << endl;
	out << "年龄：" <<e.getAge () << endl;
	out << "性别：" <<e.getGender () << endl;
	out<<"工号："<<e.workerID<<endl;
	out<<"薪水："<<e.salary<<endl;
	return out;
}
