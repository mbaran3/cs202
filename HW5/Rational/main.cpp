#include <iostream>
#include "Rational.hpp"

int main(){

    Rational<int> oneThird(1, 3);
    Rational<int> oneHalf(2, 4);
    Rational<int> one (1, 1);
    std::cout << oneThird << " " << oneHalf << std::endl;
    one = one + oneHalf;
    std::cout << "One now equals " << one << std::endl; 
    
    

    return 0;
}