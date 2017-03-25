#include"Time.h"

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

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

void Time::display() {
	cout<<setw(2)<< setfill('0')<<this->hours << " : " << setw(2) << this->minutes << " : " << setw(2) << seconds << endl;
}/**/Time Time::operator + (const Time & other)const {int h = this->hours + other.hours;int m = this->minutes + other.minutes;int s = this->seconds + other.seconds;if (s >= 60)m++;if (m >= 60)h++;return Time(h, m %= 60, s %= 60); // ����һ����ʱ����,��ʱ�����ù��캯�� }Time operator ++ (Time& t, int) {			// ��׺��������������	Time temp(t);								// ����ʱ���󱣴�����ǰ��ֵ	if (!(t.seconds = (t.seconds + 1) % 60))	 	// �ж������		if (!(t.minutes = (t.minutes + 1) % 60))	// �жϷֽ�ʱ			t.hours = (t.hours + 1) % 24;	// ������һ��	return temp;                                     	// ���ر���ԭֵ����ʱ����ֵ}Time& operator ++ (Time& t) {		// ǰ׺����������������	if (!(t.seconds = (t.seconds + 1) % 60))		if (!(t.minutes = (t.minutes + 1) % 60))			t.hours = (t.hours + 1) % 24;	return t;}
std::ostream& operator << (std::ostream& out,const Time& t) {	out  << t.hours << ":" << t.minutes << ":" << t.seconds;	return out;}Time& Time:: operator=(const Time& t){	this -> hours = t.hours;	this -> minutes = t.minutes;	this -> seconds = t.seconds;	return *this;}Time::Time(const string& s){	// ת�����캯��ʵ��	string hr(s,0,2);// ȡǰ2���ַ���ɵ��ַ���	string mn(s,3,2);// ȡ�м�2���ַ���ɵ��ַ���	string sc(s,6,2);// ȡ��2���ַ���ɵ��ַ���	istringstream sh(hr);			istringstream sm(mn);		istringstream ss(sc);	sh >> hours;// ����sh����ȡֵ��hours	sm >> minutes; // ����sm����ȡֵ��minutes	ss >> seconds; // ����sm����ȡֵ��seconds}
