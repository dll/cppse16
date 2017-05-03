#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
#include"Point.h"
#include "MyVector.h"
#include "MyStack.hpp"
#include "Employee.h"

template<typename T>
void Swap(T &a, T &b){
	T t=a;
	a=b;
	b=t;
}
void testmySwap(){
	string x,y;
	ifstream ifin("swap.data");
	ofstream ofout("swap.txt");
	while(ifin>>x>>y){
		cout<<x<<" "<<y<<endl;
		Swap(x,y);
		cout<<x<<" "<<y<<endl;
		ofout<<x<<" "<<y<<endl;
	}
	ifin.close();
	ofout.close();
}

void testMyVector(){
	string x,y;
	ifstream ifin("myvector.data");
//	double dA1[]={1.222,2.333,3.555};
//	double dA2[]={1.111, 2.222, 3.533};
	double dA1[3],dA2[3];
	for(int i=0;i<3;i++)
		ifin>>dA1[i];
	for(int i=0;i<3;i++)
		ifin>>dA2[i];
	try{
		MyVector<double> dV1(3,dA1);
		MyVector<double> dV2(3,dA2);
		dV1.display();
		dV2.display();
		MyVector<double> dV4=dV1+dV2;
		dV4.display();//  2.333      4.555      7.088
		dV4.saveMyVector("myvector.txt");
	}
	catch(string s){
		cerr<<s<<endl;
	}
	ifin.close();
}
void testMyStack(){
	string n;
	int a;
	char g;
	unsigned w;
	double s;
	
	MyStack<Employee> EmployeeStackTmp;//ÀàÊô
	EmployeeStackTmp.init();
	ifstream eifs("myEmployee.data");
	while(eifs>>n>>a>>g>>w>>s){
		Employee empn(n,a,g,w,s);
		EmployeeStackTmp.push(empn);
	}
	EmployeeStackTmp.display();
	eifs.close();
}
int main (int argc, char *argv[]) {

	testmySwap();	
	testMyVector();	
	testMyStack();
	
	return 0;
}
