#include "Money.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Money::Money(int dollar, int cent): cents(dollar*100+cent){
}
Money::Money(){
}
Money::Money(double dMoney) {
	dMoney *= 100;
	cents = std::round(dMoney);
}
std::ostream& operator<<(std::ostream& os, const Money& output){
	float money = 0.00;
	money = (output.cents * .01);
	return os << std::setprecision(2) << std::fixed << "$" << money;
}


