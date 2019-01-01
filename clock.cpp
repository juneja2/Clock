#include "clock.h"

clock::clock() {
	hours = minutes = seconds = 0;
}
clock::clock(int h, int m, int s) {
	setHours(h);
	setMinutes(m);
	setSeconds(s);
}
void clock::setHours(int h) {
	if (h < 0)
		hours = 0;
	else if (h >= 24)
		hours = h - 24;
	else hours = h;
}
void clock::setMinutes(int m) {
	if (m < 0)
		minutes = 0;
	else if (m >= 60)
		minutes = minutes - 60;
	else minutes = m;
}
void clock::setSeconds(int s) {
	if (s < 0 )
		seconds = 0;
	else if (s >= 60) {
		seconds = s - 60;
	}
	else  seconds = s;
}
int clock::getHours()const {
	return hours;
}
int clock::getMinutes() const {
	return minutes;
}
int clock::getSecond() const {
	return seconds;
}
clock clock::operator++() {
	if (++seconds == 60) {
		seconds = 0;
		if (++minutes == 60) {
			minutes = 0;
			if (++hours == 24)
				hours = 0;
		}
	}
	return *this;
}
clock clock::operator++(int s) {
	clock temp = *this;
	if (++seconds == 60) {
		seconds = 0;
		if (++minutes == 60) {
			minutes = 0;
			if (++hours == 24)
				hours = 0;
		}
	}
	return temp;
}
bool clock::operator== (const clock &clockType)const {
	return (hours == clockType.hours &&  minutes == clockType.minutes && seconds == clockType.seconds);
}
bool clock::operator!=(const clock &clockType)const {
	return(hours != clockType.hours || minutes != clockType.minutes || seconds != clockType.seconds);
}
bool clock::operator>(const clock &clockType)const {
	if (hours == clockType.hours) {
		if (minutes == clockType.minutes) {
			if (seconds <= clockType.seconds) return false;
			else return true;
		}
		else if (minutes > clockType.minutes) return true;
		//if minutes are neither greater than nor equal to then it must be less than
		else return false;
	}
	else if (hours > clockType.hours) return true;
	// if hours are neither greater than nor equal to then it must be less than
	else return false;
}
bool clock::operator<(const clock &clockType)const {
	return (*this != clockType && clockType > *this);
	// if clockType > *this and not equal to *this then this condition returns true 
	// This means that *this is smaller than clockType so it should return true
}
bool clock::operator>=(const clock &clockType)const {
	return (*this > clockType || *this == clockType);
}
bool clock::operator<=(const clock &clockType)const {
	return (*this < clockType || *this == clockType);
}
ostream& operator<<(ostream& out, const clock& clockType) {
	out	 << "Time =" << (clockType.hours < 10 ? " 0": " " ) << clockType.hours 
		 << (clockType.minutes < 10 ? ":0" : ":") << clockType.minutes 
		 << (clockType.seconds < 10 ? ":0" : ":") << clockType.seconds << endl;
	return out;
}
istream& operator>>(istream& in, clock&clockType) {
	cout << "Please enter hour, minutes seconds separated by space ";
	in >> clockType.hours >> clockType.minutes >> clockType.seconds;
	if (clockType.seconds >= 60) {
		clockType.seconds -= 60;
		if (++clockType.minutes >= 60) {
			clockType.minutes -= 60;
			if (++clockType.hours >= 24)
				clockType.hours -= 24;
		}
	}
	else if (clockType.minutes >= 60) {
		clockType.minutes -= 60;
		if (++clockType.hours >= 24)
			clockType.hours -= 24;
	}
	else if(clockType.hours >= 24)
		clockType.hours -= 24;
	return in;
}
