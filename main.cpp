#include <string>
#include <iostream>
#include <boost/format.hpp>
#include "StockQuote.hpp"
#include "StockQuoteGenerator.hpp"

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		StockQuote sq = StockQuoteGenerator::generateStockQuote(argv[i]);
		std::cout <<  boost::format("%-5s %7.2f  %+7.2f (%+5.2f%%)") % sq.symbol % sq.price % sq.change % sq.chg_percent << std::endl;
	}
}
