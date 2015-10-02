#include <string>
#include <iostream>
#include <iomanip>
#include <boost/format.hpp>
#include <boost/program_options.hpp>
#include "StockQuote.hpp"
#include "StockQuoteGenerator.hpp"

int main(int argc, char** argv) {

	try {
		// Set up program options for boost::program_options
		namespace po = boost::program_options;
		po::options_description options_desc;
		po::options_description desc("Program Options");
		desc.add_options()
			("help,h", "show help message")
			("detail,d", "show detailed view")
			("long,l", "show long detailed view")
			("show-name,n", "show names as well as symbols")
			;
		// Create hidden options to be used for positional options later
		po::options_description hidden("Hidden options");
		hidden.add_options()
			("symbol", po::value< std::vector<std::string> >(), "selected stock symbols")
			;

		// Add both sets of options to the description to ensure they get displayed
		options_desc.add(hidden).add(desc);

		po::positional_options_description p;
		p.add("symbol", -1);

		po::variables_map vm;
		po::store(po::command_line_parser(argc, argv).options(options_desc).positional(p).run(), vm);
		po::notify(vm); 

		if (vm.count("help")) {
			std::cout << "Usage: " << argv[0] << ": [options] symbol..." << std::endl;
			std::cout << desc << std::endl;
			return 1;
		}

		if(vm.count("symbol")){
			std::vector<std::string> symbols = vm["symbol"].as<std::vector<std::string>>();
			// Loop through all of the positional "symbol" arguments
			for(int i=0; i<symbols.size(); i++) {
				std::string symbol = symbols[i];
				try {
					StockQuote sq = StockQuoteGenerator::generateStockQuote(symbol);
					if (sq.name == "FAILED") {
						std::cerr << "Could not retrieve: " << sq.symbol << std::endl;	
						continue;
					}
					if (vm.count("detail")) {
						// Display field names every 5th quote.
						if (i % 5 == 0) {
							std::cout << std::string(74, '-') << std::endl;
							std::cout <<  boost::format("%-7s %7s %7s %8s %7s %7s %7s %7s %9s") 
								% "SYMBOL" % "PRICE" % "CHG" % "CHG%" % "DLOW" % "DHIGH" % "YLOW" % "YHIGH" % "VOLUME" << std::endl;
							std::cout << std::string(74, '-') << std::endl;
						}
						if (vm.count("show-name")) std::cout << sq.name << std::endl;
						std::cout <<  boost::format("%-7s %7.2f %+7.2f %+7.2f%% %7.2f %7.2f %7.2f %7.2f %9.0f") 
							% sq.symbol % sq.price % sq.change % sq.chg_percent % sq.day_low % sq.day_high % sq.year_low % sq.year_high % sq.volume  << std::endl;
					}
					else if (vm.count("long")) {
						std::cout << std::fixed << std::setprecision(2)
						<< "Name: " << sq.name << std::endl 
						<< "Symbol: " << sq.symbol << std::endl 
						<< "Price: " << sq.price << std::endl 
						<< "Change: " << sq.change << std::endl 
						<< "Change (%): " << sq.chg_percent << std::endl 
						<< "Day Low: " << sq.day_low << std::endl 
						<< "Day High: " << sq.day_high << std::endl 
						<< "Year Low: " << sq.year_low << std::endl 
						<< "Year High: " << sq.year_high << std::endl 
						<< "Volume: " << sq.volume << std::endl;
					}
					else {
						if (vm.count("show-name")) std::cout << sq.name << std::endl;
						std::cout <<  boost::format("%-5s %7.2f  %+7.2f (%+5.2f%%)") % sq.symbol % sq.price % sq.change % sq.chg_percent << std::endl;
					}
				}
				catch(std::exception& e) { 
					std::cerr << "Could not retrieve: " << symbol << std::endl; 
				}

			}
		}
		else {
			std::cout << "You must specify one or more stock symbols. (-h for help)" << std::endl;
			return 1;
		}


	}

	catch(std::exception& e) { 
		std::cerr <<  e.what() << std::endl; 
		return 2; 

	} 
}
