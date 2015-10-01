#ifndef STOCKQUOTEGENERATOR_HPP
#define STOCKQUOTEGENERATOR_HPP
#include "StockQuote.hpp"
#include <string>
namespace StockQuoteGenerator {
StockQuote generateStockQuote(std::string request_symbol);
}
#endif
