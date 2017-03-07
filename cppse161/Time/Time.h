#pragma once

#include<iostream>//标准流操作
#include<iomanip>//格式输出
#include<sstream>//转换函数

using namespace std;

class Time {
private:
	int hours;//时
	int minutes;//分
	int seconds;//秒

public:
	Time() {}
	Time(int hours, int minutes, int seconds);//构造函数
	Time(const string& s);//转换构造函数，XX:XX:XX字符串转换成时分秒

	void display();//显示时间

	//友元函数实现：友元函数可以访问类的私有成员
	friend Time operator + (const Time &t1, const Time &t2);	// 友元函数声明
	friend Time& operator ++ (Time& t);		// 前缀增量符重载函数
	friend Time operator ++ (Time& t, int);		// 后缀增量符重载函数
	friend ostream& operator << (ostream& out, const Time& t);//插入操作符重载函数
	friend istream & operator >> (istream &in, Time &t);//抽取操作符重载函数
	
	//成员函数实现：封装性更好（不能对私有数据成员访问）
	//Time operator + (const Time & other)const;//操作符+重载，实现两个时间相加
	Time& operator ++ ();//++前缀重载
	Time  operator ++ (int);//后缀++重载
	Time& operator=(const Time& t);//赋值=重载
};
