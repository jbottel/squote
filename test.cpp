#define BOOST_TEST_MODULE StockQuoteTest
#include <boost/test/included/unit_test.hpp>
#include "StockQuote.hpp"

BOOST_AUTO_TEST_SUITE (StockQuoteTest)

BOOST_AUTO_TEST_CASE (StockQuoteConstruction) { 
	StockQuote s(-0.54,-4.3,33.53,17.23,"Testing Industries","Testing Inc.",22.42,"TSTI",2322.0,"equity","2015-01-01T00:00:01+0000",4573658,35.23,15.53); BOOST_REQUIRE(s.change == -0.54);
	BOOST_REQUIRE(s.chg_percent == -4.3);
	BOOST_REQUIRE(s.day_high == 33.53);
	BOOST_REQUIRE(s.day_low == 17.23);
	BOOST_REQUIRE_EQUAL(s.issuer_name, "Testing Industries");
	BOOST_REQUIRE_EQUAL(s.name, "Testing Inc.");
	BOOST_REQUIRE(s.price == 22.42);
	BOOST_REQUIRE_EQUAL(s.symbol, "TSTI");
	BOOST_REQUIRE(s.ts == 2322);
	BOOST_REQUIRE_EQUAL(s.type, "equity");
	BOOST_REQUIRE_EQUAL(s.utctime, "2015-01-01T00:00:01+0000");
	BOOST_REQUIRE(s.volume == 4573658);
	BOOST_REQUIRE(s.year_high == 35.23);
	BOOST_REQUIRE(s.year_low == 15.53);
}

BOOST_AUTO_TEST_CASE (StockQuoteToSimpleString) {
	StockQuote s(-0.54,-4.3,33.53,17.23,"Testing Industries","Testing Inc.",22.42,"TSTI",2322.0,"equity","2015-01-01T00:00:01+0000",4573658,35.23,15.53); 
	BOOST_REQUIRE(s.change == -0.54);
	BOOST_REQUIRE_EQUAL(s.toStringSimple(), "TSTI    22.42    -0.54 (-4.30%)");
}

BOOST_AUTO_TEST_CASE (StockQuoteToDetailedString) {
	StockQuote s(0.54,4.3,33.53,17.23,"Testing Industries","Testing Inc.",25.20,"TSTI",2322.0,"equity","2015-01-01T00:00:01+0000",4573658,35.23,15.53); 
	BOOST_REQUIRE(s.change == 0.54);
	BOOST_REQUIRE_EQUAL(s.toStringDetail(), "TSTI      25.20   +0.54   +4.30%   17.23   33.53   15.53   35.23   4573658");
}




BOOST_AUTO_TEST_SUITE_END()
