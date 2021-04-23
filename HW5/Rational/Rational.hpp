#include <iostream>
#include <numeric>

template<typename T>
class Rational{

    template<typename Y>
    friend std::ostream& operator << (std::ostream& os, const Rational<Y> &obj);
    template<typename Y>
    friend Rational<Y> operator + (const Rational<Y> &left, const Rational<Y> right);
    template<typename Y>
    friend Rational<Y> operator - (const Rational<Y> &left);
    
public:

   Rational<T> & operator +=(const Rational<T> &right);
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
template<typename T>
Rational<T>&  Rational<T>::operator += (const Rational<T> &right){
    _numerator = _numerator * right._denominator + right._numerator * _denominator;
    _denominator = right._denominator * _denominator;
    reduce();
    return *this;
}
template<typename T>
Rational<T> operator + (const Rational<T> &left, const Rational<T> right){
    auto holder = left;
    holder += right;
    return holder;
}
template<typename Y>
Rational<Y> operator - (const Rational<Y> &left){
    return { -left._numerator, left._denominator};
} 
template<typename T>
Rational<T> operator - (const Rational<T> &left, const Rational<T> &right){
    return left  + -right;
}
   