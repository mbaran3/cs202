#include "Money.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Money::Money(int cent, int dollar): cents(dollar*100+cent){
}
Money::Money(){
}
Money::Money(double dMoney) {
	dMoney *= 100;
	cents = std::round(dMoney);
}
std::ostream& operator<<(std::ostream& os, const Money& output){
	float money = 0.00;
	money = std::abs((output.cents * .01));
	if(output.cents < 0)
		os << std::setprecision(2) << std::fixed << "-$" << money;
	else
		os << std::setprecision(2) << std::fixed << "$" << money;

	return os;
}
bool operator==(const Money& left, const Money& right) {
	return left.cents == right.cents;
}
bool operator!=(const Money& left, const Money& right){
	return !(left == right);
}
bool operator < (const Money& left, const Money& right) {
	return left.cents < right.cents;
}
bool operator > (const Money& left, const Money& right) {
	return right < left;
}
bool operator <= (const Money& left, const Money& right) {
	return !(left > right);
}
bool operator >= (const Money& left, const Money& right) {
	return !(left < right);
}