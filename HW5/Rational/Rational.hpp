#include <iostream>

template<typename T>
class Rational{

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
