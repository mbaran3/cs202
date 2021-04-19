#include <iostream>

template<typename T>
class Rational{

    template<typename Y>
    friend std::ostream& operator << (std::ostream& os, const Rational<Y> &obj);

public:

    Rational(T numerator, T denominator);

private:
   
    T _numerator;
    T _denominator;

};
template<typename T>
Rational<T>::Rational(T numerator, T denominator):_numerator(numerator),
 _denominator(denominator) {
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Rational<T> &obj){
    return os << obj._numerator << "/" << obj._denominator;
}

