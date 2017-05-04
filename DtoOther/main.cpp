#include "DtoOther.h"
#include "Express.h"
#include "StackCalculator.h"
#include "Calculator.h"
#include<iostream>
#include<cstdio>

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
void testArithmeticExpression(){
	double ans = 0; 
	string exp="";
	
	cout << "请输入计算式：";	
	cin >> exp;  
	ArithmeticExpression expess(exp);
	ans = expess.calcExp();  
	printf("%.2f\n", ans);  
}
void testStackCalculator(){
	cout << "请输入计算式：";
	string equation="";
	getline(cin, equation);
	cout << StackCalculator()(equation);
}
void testMapCalculator(){
//	MapCalculator exp=new MapCalculator(); 
//	exp.transform("(1+2)*3-5+8+(1+2)*3-5+8"); 
}
int main (int argc, char *argv[]) {

	testDtoOther();
	
//	testArithmeticExpression(); 
	
//	testStackCalculator();
	
	testCalculator();
	return 0;
}

/*
3+(12/(2*2+1))
5.40
*/
