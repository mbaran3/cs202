#include "Money.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Money::Money(int cent, int dollar): _cents(dollar*100+cent){
}
Money::Money(){
}
Money::Money(double dMoney) {
	dMoney *= 100;
	_cents = std::round(dMoney);
}
std::ostream& operator<<(std::ostream& os, const Money& output){
	float money = 0.00;
	money = std::abs((output._cents * .01));
	if(output._cents < 0)
		os << std::setprecision(2) << std::fixed << "-$" << money;
	else
		os << std::setprecision(2) << std::fixed << "$" << money;

	return os;
}
bool operator==(const Money& left, const Money& right) {
	return left._cents == right._cents;
}
bool operator!=(const Money& left, const Money& right){
	return !(left == right);
}
bool operator < (const Money& left, const Money& right) {
	return left._cents < right._cents;
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



Money& Money::operator +=(const Money& right) {
	_cents = _cents + right._cents;
	return *this;
}
Money operator +(const Money& left, const Money& right) {
	auto temp{ left };
	temp += right;
	return temp;
}
Money operator -(const Money& left) {
	return { -left._cents };
}
Money operator -(const Money& left, const Money& right) {
	return left + -right;
}
Money& Money::operator-=(const Money& right) {
	*this = *this - right;
	return *this;
}
Money& Money::operator*=(const Money& right) {
	 _cents *= right._cents;
	 return *this;
}
Money& Money::operator/=(const Money& right) {
	_cents /= right._cents;
	return *this;
}
Money operator/(Money left, const Money& right) {
	return left /= right;
}
Money operator*(Money left, const Money& right) {
	return left *= right;
}
Money& Money::operator*=(const double dTimes) {
	_cents = _cents * dTimes;
	return *this;
}
Money& Money::operator/=(const double dDivid) {
	_cents = _cents / dDivid;
	return *this;
}



