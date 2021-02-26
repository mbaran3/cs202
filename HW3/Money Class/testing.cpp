#include <iostream>
#include "Catch2.hpp"
#include <sstream>
#include "Money.hpp"

TEST_CASE( "Money ctors and operator<<") {
   const Money con0;
   const Money con1(2);
   const Money con2(2.02);
   const Money con3(-3.03);
   std::ostringstream os;
   os << con0;
   REQUIRE(os.str() == "$0.00");
   os.str(""); //reset output holder
   os << con1;
   REQUIRE(os.str() == "$0.02");

   os.str(""); //reset output holder
   os << con2;
   REQUIRE(os.str() == "$2.02");

   os.str("");
   os << con3;
   REQUIRE(os.str() == "-$3.03");

   const Money con4(7.072);
   os.str("");
   os << con4;
   REQUIRE(os.str() == "$7.07");

   const Money con5(7.077);
   os.str("");
   os << con5;
   REQUIRE(os.str() == "$7.08");

   const Money con6(-7.072);
   os.str("");
   os << con6;
   REQUIRE(os.str() == "-$7.07");

   const Money con7(-7.077);
   os.str("");
   os << con7;
   REQUIRE(os.str() == "-$7.08");
}
TEST_CASE("Money relational operators") {
	const Money m0;
	const Money m1(1);

	REQUIRE((m0 == m0));
	REQUIRE(!(m0 == m1));

	REQUIRE(!(m0 != m0));
	REQUIRE((m0 != m1));

	//REQUIRE(!(m0 < m0));
	//REQUIRE((m0 < m1));
	//REQUIRE(!(m1 < m0));

	//REQUIRE((m0 <= m0));
	//REQUIRE((m0 <= m1));
	//REQUIRE(!(m1 <= m0));

	//REQUIRE(!(m0 > m0));
	//REQUIRE(!(m0 > m1));
	//REQUIRE((m1 > m0));

	//REQUIRE((m0 >= m0));
	//REQUIRE(!(m0 >= m1));
	//REQUIRE((m1 >= m0));
}