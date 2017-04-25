#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"

class Manager : public Employee {
private:
	string	post;//ְλ
protected:
public:
	//Manager(){}
	Manager(std::string name,int age,char gender
			, unsigned int workerID, double salary,string post);
	~Manager();
	string getPost() const{return post;}
	void Output();
};

#endif

