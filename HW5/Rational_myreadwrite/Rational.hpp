#ifndef RATIONAL_HPP
#define RATIONAL_HPP
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
    template<typename Y>
    friend bool operator == (const Rational<Y> &left, const Rational<Y> &right);
    template<typename Y>
    friend bool operator < (const Rational<Y> &left, const Rational<Y> &right);

    
public:


   Rational<T>& operator -= (const Rational<T> &right);
   Rational<T>& operator /= (const Rational<T> &right); 
   Rational<T>& operator *= (const Rational<T> &right);
   Rational<T>& operator += (const Rational<T> &right);
   Rational(T numerator, T denominator = 1);
   Rational();

    
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
Rational<T>::Rational(): _numerator(T()), _denominator(T()){}
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
   if(obj._numerator == 0)
      return os << "0";
   else
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
template<typename T>
Rational<T>& Rational<T>::operator -= (const Rational<T> &right){
   return *this = *this -right;
}
template<typename Y>
Rational<Y> operator - (const Rational<Y> &left){
    return { -left._numerator, left._denominator};
} 
template<typename T>
Rational<T> operator - (const Rational<T> &left, const Rational<T> &right){
    return left  + -right;
}
template<typename T>
Rational<T>& Rational<T>::operator *=(const Rational<T> &right){
    _numerator *= right._numerator;
    _denominator *= right._denominator;
    reduce();
    return *this;
}
template<typename T>
Rational<T> operator * (const Rational<T> &left, const Rational<T> &right){
   Rational<T> holder = left;
   holder *= right;
   return holder;    
}
template<typename T>
Rational<T> operator / (const Rational<T> & left, const Rational<T> &right){
   Rational<T> holder = left;
   holder /= right;
   return holder;
}
template<typename T> 
Rational<T> & Rational<T>::operator /= (const Rational<T> &right){
    Rational<T> inverse(right._denominator, right._numerator);
    return *this *= inverse;
}
template<typename T>
bool operator == (const Rational<T> &left, const Rational<T> &right){
    return left._numerator == right._numerator && left._denominator == right._denominator;
} 
template<typename Y>
bool operator < (const Rational<Y> &left, const Rational<Y> &right){
    return left._numerator*right._denominator < left._denominator*right._numerator; 
}
template<typename T>
bool operator <= (const Rational<T> &left, const Rational<T> &right){
   return !(right < left);      
}
template<typename T>
bool operator != (const Rational<T> &left, const Rational<T> &right){
   return !(left == right); 
}
template<typename T>
bool operator >= (const Rational<T> &left, const Rational<T> &right){
   return !(right < left);
}
template<typename T>
bool operator > (const Rational<T> &left, const Rational<T> &right){
   return right < left;
}


#endif
