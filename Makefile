Main:
	clang++-3.5 -std=c++11 tinyxml2/tinyxml2.cpp StockQuote.cpp -o squote -I/usr/local/include/cpp-netlib -lboost_regex -lboost_date_time -lboost_thread -lboost_system -lcppnetlib-client-connections -lcppnetlib-uri -lssl -lcrypt	-pthread


OldOne:
	g++ StockQuote.cpp -o squote -lboost_system -lboost_thread -pthread -lssl -lcrypt
	

