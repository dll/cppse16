#pragma once

#include<iostream>//��׼������
#include<iomanip>//��ʽ���
#include<sstream>//ת������

using namespace std;

class Time {
private:
	int hours;//ʱ
	int minutes;//��
	int seconds;//��

public:
	Time() {}
	Time(int hours, int minutes, int seconds);//���캯��
	Time(const string& s);//ת�����캯����XX:XX:XX�ַ���ת����ʱ����

	void display();//��ʾʱ��

	//��Ԫ����ʵ�֣���Ԫ�������Է������˽�г�Ա
	friend Time operator + (const Time &t1, const Time &t2);	// ��Ԫ��������
	friend Time& operator ++ (Time& t);		// ǰ׺���������غ���
	friend Time operator ++ (Time& t, int);		// ��׺���������غ���
	friend ostream& operator << (ostream& out, const Time& t);//������������غ���
	friend istream & operator >> (istream &in, Time &t);//��ȡ���������غ���
	
	//��Ա����ʵ�֣���װ�Ը��ã����ܶ�˽�����ݳ�Ա���ʣ�
	//Time operator + (const Time & other)const;//������+���أ�ʵ������ʱ�����
	Time& operator ++ ();//++ǰ׺����
	Time  operator ++ (int);//��׺++����
	Time& operator=(const Time& t);//��ֵ=����
};
