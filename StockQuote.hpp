#ifndef STOCKQUOTE_HPP
#define STOCKQUOTE_HPP
#include <string>

class StockQuote {
	public:
		double change;
		double chg_percent;
		double day_high;
		double day_low;
		std::string issuer_name;
		std::string name;
		double price;
		std::string symbol;
		double ts;
		std::string type;
		std::string utctime;
		double volume;
		double year_high;
		double year_low;
	public:
		StockQuote(double change, double chg_percent, double day_high, double day_low, std::string issuer_name, std::string name, double price, std::string symbol, double ts, std::string type, std::string utctime, double volume, double year_high, double year_low);

		std::string toStringSimple(); 
		std::string toStringLong();
		std::string toStringDetail();
		std::string detailStringLabels();


};
#endif
