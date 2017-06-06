#include "DtoOther.h"
#include "DeStackExpression.h"
#include "StackCalculator.h"
#include "StackCalculator1.h"
#include "StackCalculator2.h"
#include "PriorityCalcultor.h"
#include<iostream>
#include<cstdio>
#include<fstream>

using namespace std;
void testDtoOther(){
	DtoOther dto1(32767,16); 
	dto1.convert();	
	DtoOther dto2(32767,8); 
	dto2.convert();
	DtoOther dto3(32767,2); 
	dto3.convert();
	DtoOther dto4(32767,12); 
	dto4.convert();
	DtoOther dto5(32767,4); 
	dto5.convert();
}
void testDeStackExpression(){
 
}
void testDeStackExpressionFile(){
	double ans = 0; 
	string exp="";
	ifstream fin("ssexpress.txt");
	ofstream fout("result.txt");
 
	fin.close();
	fout.close();
}
void testStackCalculator(){
	cout << "ÇëÊäÈë¼ÆËãÊ½£º";
	string equation="";
	getline(cin, equation);
	equation+="=";
	cout << StackCalculator()(equation)<<endl;
	cout << StackCalculator1()(equation)<<endl;
	cout << StackCalculator2()(equation)<<endl;
}
void testPriorityCalcultor(){
	PriorityCalcultor pc;
	pc.Calculator();
}

int main (int argc, char *argv[]) {

//	testDtoOther();
	
//	testDeStackExpression(); 
	testDeStackExpressionFile();
	
//	testStackCalculator();
	
//	testPriorityCalcultor();
	
	return 0;
}

/*
3+(12/(2*2+1))
5.40
*/
