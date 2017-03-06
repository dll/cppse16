#pragma once

#include<iostream>
#include<iomanip>

class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time(int hours, int minutes, int seconds);

	friend Time operator + (const Time &t1, const Time &t2);	// ÓÑÔªº¯ÊıÉùÃ÷
	void display();
};