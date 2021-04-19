#include <iostream>
#include "Rational.hpp"

int main(){

    Rational<int> oneThird(1, 3);

    std::cout << oneThird;

    return 0;
}