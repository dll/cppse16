#ifndef EXPRESS_H
#define EXPRESS_H

#include<iostream>
#include<stack>
#include<string>
#include<cstdio>

using namespace std; 
class DeStackExpression{
	stack<char> opStack;  
	stack<double> numStack;  
	string orgExp;//��ʼ���ʽ
	string postExp;//��׺���ʽ 	
public:
	DeStackExpression(string ptrExp){
		orgExp=ptrExp;
		OrgExpTranslatePostExp();
	}
	//��׺���ʽת�ɺ�׺���ʽ
	//3+(12/(2*2+1))-->3 12 2 2 *1 +/+
	void OrgExpTranslatePostExp();
	//�����׺���ʽ
	double CalcPostExp();
	//��ȡ��׺���ʽ�ַ���
	string getPostExp();
};

#endif

