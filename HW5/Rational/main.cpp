#include <iostream>
#include "Rational.hpp"

int main(){

    Rational<int> oneThird(1, 3);
    Rational<int> twoSixiths(2, 6);
    std::cout << oneThird << " " << twoSixiths << std::endl;

    return 0;
}