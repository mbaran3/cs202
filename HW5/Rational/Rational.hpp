#include <iostream>
#include <numeric>

template<typename T>
class Rational{

    template<typename Y>
    friend std::ostream& operator << (std::ostream& os, const Rational<Y> &obj);

public:

    Rational(T numerator, T denominator);
    

private:
    
    void reduce();
    T _numerator;
    T _denominator;

};
template<typename T>
Rational<T>::Rational(T numerator, T denominator):_numerator(numerator),
 _denominator(denominator) {
     reduce();
}
template<typename T>
void Rational<T>::reduce(){

    T gcd = std::gcd(_denominator, _numerator);
    _denominator/=gcd;
    _numerator/=gcd;
    if(_denominator < 0){
        _denominator *= -1;
        _numerator *= -1;
    }
}



template<typename T>
std::ostream& operator << (std::ostream& os, const Rational<T> &obj){
    return os << obj._numerator << "/" << obj._denominator;
}

