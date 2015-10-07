#include <string>
#include <iostream>
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
							std::cout << sq.detailStringLabels();
						}
						if (vm.count("show-name")) std::cout << sq.name << std::endl;
						std::cout << sq.toStringDetail() << std::endl;
					}
					else if (vm.count("long")) {
						std::cout << sq.toStringLong() << std::endl;
					}
					else {
						if (vm.count("show-name")) std::cout << sq.name << std::endl;
						std::cout << sq.toStringSimple() << std::endl;
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
