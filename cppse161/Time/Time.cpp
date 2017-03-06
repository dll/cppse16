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
}
