
#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {
	friend std::ostream& operator << (std::ostream& os, const Money& output);
	friend bool operator== (Money a, Money b);
	friend bool operator!= (Money a, Money b);

public:
	Money();
	Money(int cent, int dollar = 0);
	Money(double dMoney);
	
private:
	int cents = 0;

};

#endif // !MONEY_H
