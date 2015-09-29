#include <string>
#include "StockQuote.hpp"

StockQuote::StockQuote(double change, double chg_percent, double day_high, double day_low, std::string issuer_name, std::string name, double price, std::string symbol, double ts, std::string type, std::string utctime, double volume, double year_high, double year_low) : change(change), chg_percent(chg_percent), day_high(day_high), day_low(day_low), issuer_name(issuer_name), name(name), price(price), symbol(symbol), ts(ts), type(type), utctime(utctime), volume(volume), year_high(year_high), year_low(year_low) {} 
