
#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {

	friend std::ostream& operator << (std::ostream& os, const Money& output);
	friend bool operator== (const Money& a, const Money& b);
	friend bool operator < (const Money& a, const Money& b);
	friend Money operator +(const Money& left, const Money& right);
	friend Money operator -(const Money& left);

public:

	Money();
	Money(int cent, int dollar = 0);
	Money(double dMoney);
	Money& operator +=(const Money& right);
	Money& operator -=(const Money& right);


private:
	int _cents = 0;

};

Money operator -(const Money& left, const Money& right);


bool operator != (const Money& a, const Money& b);
bool operator >(const Money& a, const Money& b);
bool operator <=(const Money& a, const Money& b);
bool operator >=(const Money& a, const Money& b);

#endif // !MONEY_H
