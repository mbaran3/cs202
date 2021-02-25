#include <iostream>
#include "Catch2.hpp"
#include <sstream>
#include "Money.h"

TEST_CASE("Testing initialization") {

	std::ostringstream out;
	Money nothing;
	Money dollarCents(1, 99);
	Money usingDouble(1.99);
	out << nothing;
	REQUIRE(out.str() == "$0.00");
	out.str("");
	out << dollarCents;
	REQUIRE(out.str() == "$1.99");
	out.str("");
	out << usingDouble;
	REQUIRE(out.str() == "$1.99");
	
}