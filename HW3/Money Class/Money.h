
#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money {
	friend std::ostream& operator << (std::ostream& os, const Money& output);

public:
	Money();
	Money(int dollar, int cent);
	Money(double dMoney);
	
private:
	int cents = 0;

};

#endif // !MONEY_H
