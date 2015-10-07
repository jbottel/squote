#include <string>
#include <iomanip>
#include <sstream>
#include "StockQuote.hpp"
#include <boost/format.hpp>

StockQuote::StockQuote(double change, double chg_percent, double day_high, double day_low, std::string issuer_name, std::string name, double price, std::string symbol, double ts, std::string type, std::string utctime, double volume, double year_high, double year_low) : change(change), chg_percent(chg_percent), day_high(day_high), day_low(day_low), issuer_name(issuer_name), name(name), price(price), symbol(symbol), ts(ts), type(type), utctime(utctime), volume(volume), year_high(year_high), year_low(year_low) {} 

std::string StockQuote::toStringSimple() {
	return (boost::format("%-5s %7.2f  %+7.2f (%+5.2f%%)") % symbol % price % change % chg_percent).str();
}

std::string StockQuote::toStringLong() {
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2)
	<< "Name: " << name << std::endl 
	<< "Symbol: " << symbol << std::endl 
	<< "Price: " << price << std::endl 
	<< "Change: " << change << std::endl 
	<< "Change (%): " << chg_percent << std::endl 
	<< "Day Low: " << day_low << std::endl 
	<< "Day High: " << day_high << std::endl 
	<< "Year Low: " << year_low << std::endl 
	<< "Year High: " << year_high << std::endl 
	<< "Volume: " << volume;
	return ss.str();
}

std::string StockQuote::toStringDetail() {
	return (boost::format("%-7s %7.2f %+7.2f %+7.2f%% %7.2f %7.2f %7.2f %7.2f %9.0f") 
			% symbol % price % change % chg_percent % day_low % day_high % year_low % year_high % volume).str();
}

std::string StockQuote::detailStringLabels() {
	std::stringstream ss;
	ss << std::string(74, '-') << std::endl;
	ss << boost::format("%-7s %7s %7s %8s %7s %7s %7s %7s %9s") 
		% "SYMBOL" % "PRICE" % "CHG" % "CHG%" % "DLOW" % "DHIGH" % "YLOW" % "YHIGH" % "VOLUME" << std::endl;
	ss << std::string(74, '-') << std::endl;
	return ss.str();
}
