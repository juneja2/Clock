#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>
using namespace std;

class clock {
public:
	friend ostream& operator<<(ostream&, const clock&);
	friend istream& operator>>(istream&, clock&);
	clock operator++();
	clock operator++(int s);

	bool operator== (const clock &clockType)const;
	bool operator!=(const clock &clockType)const;
	bool operator>(const clock &clockType)const;
	bool operator<(const clock &clockType)const;
	bool operator>=(const clock &clockType)const;
	bool operator<=(const clock &clockType)const;

	clock();
	clock(int h, int m, int s);

	void setHours(int h);
	void setMinutes(int m);
	void setSeconds(int s);

	int getHours()const;
	int getMinutes() const;
	int getSecond() const;
private : 
	int hours;
	int minutes;
	int seconds;
};
#endif
