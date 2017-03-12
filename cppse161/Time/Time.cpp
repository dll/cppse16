#include"Time.h"

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}
void Time::Display() {
	cout << setw(2) << setfill('0') << this->hours << ":" << setw(2) << this->minutes << ":" << setw(2) << seconds << endl;
}

//成员函数实现
//两个Time对象相加
Time operator + (const Time &t1, const Time &t2) {
	Time t(0, 0, 0);
	t.seconds = t1.seconds + t2.seconds;
	if (t.seconds >= 60) {
		t.minutes++;
		t.seconds %= 60;
	}
	t.minutes = t.minutes + t1.minutes + t2.minutes;
	if (t.minutes >= 60) {
		t.hours++;
		t.minutes %= 60;
	}
	t.hours = t.hours + t1.hours + t2.hours;
	return t;
}

/*
Time Time::operator + (const Time & other)const {
	int h = this->hours + other.hours;
	int m = this->minutes + other.minutes;
	int s = this->seconds + other.seconds;
	if (s >= 60)m++;
	if (m >= 60)h++;
	return Time(h, m %= 60, s %= 60); // 返回一个临时对象,这时将调用构造函数 
}*/

Time operator ++ (Time& t, int) {			// 后缀增量操作符重载
	Time temp(t);								// 用临时对象保存增量前的值
	if (!(t.seconds = (t.seconds + 1) % 60))	 	// 判断秒进分
		if (!(t.minutes = (t.minutes + 1) % 60))	// 判断分进时
			t.hours = (t.hours + 1) % 24;	// 进入下一天
	return temp;                                     	// 返回保存原值的临时对象值
}
Time& operator ++ (Time& t) {		// 前缀增量操作符重重载，原理类似后缀++
	if (!(t.seconds = (t.seconds + 1) % 60))
		if (!(t.minutes = (t.minutes + 1) % 60))
			t.hours = (t.hours + 1) % 24;
	return t;
}
//插入操作符重载函数
ostream& operator << (ostream& out, const Time& t) {
	out << setw(2) << setfill('0') << t.hours << ":" << t.minutes << ":" << t.seconds;
	return out;
}
//抽取操作符重载函数
istream & operator >> (istream &in, Time &t)
{
	in >> t.hours >> t.minutes>>t.seconds;
	return in;
}

//赋值操作符重载函数
Time& Time:: operator=(const Time& t) {
	this->hours = t.hours;
	this->minutes = t.minutes;
	this->seconds = t.seconds;
	return *this;
}
Time::Time(const string& s) {	// 转换构造函数实现
	string hr(s, 0, 2);// 取前2个字符组成的字符串
	string mn(s, 3, 2);// 取中间2个字符组成的字符串
	string sc(s, 6, 2);// 取后2个字符组成的字符串
	istringstream sh(hr);
	istringstream sm(mn);
	istringstream ss(sc);
	sh >> hours;// 从流sh中提取值到hours
	sm >> minutes; // 从流sm中提取值到minutes
	ss >> seconds; // 从流sm中提取值到seconds
}
