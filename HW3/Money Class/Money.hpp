
#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {
	friend std::ostream& operator << (std::ostream& os, const Money& output);
	friend bool operator== (const Money& a, const Money& b);
	friend bool operator < (const Money& a, const Money& b);


public:

	Money();
	Money(int cent, int dollar = 0);
	Money(double dMoney);
	
private:
	int cents = 0;

};
bool operator != (const Money& a, const Money& b);
bool operator >(const Money& a, const Money& b);
bool operator <=(const Money& a, const Money& b);
bool operator >=(const Money& a, const Money& b);

#endif // !MONEY_H
