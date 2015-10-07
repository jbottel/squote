COMPILER=clang++-3.5
FLAGS=-std=c++11 -Wall
CMPL_CMD=$(COMPILER) $(FLAGS)
LNK_FLAGS=-I/usr/local/include/cpp-netlib -lboost_regex -lboost_date_time -lboost_thread -lboost_system -lcppnetlib-client-connections -lcppnetlib-uri -lssl -lcrypt -lboost_program_options -pthread
LNK_CMD=$(LNK_FLAGS)


squote: StockQuoteGenerator.o StockQuote.o tinyxml2.o main.o
	$(CMPL_CMD) main.o StockQuote.o StockQuoteGenerator.o tinyxml2.o -o squote $(LNK_CMD)

main.o: StockQuote.o StockQuoteGenerator.o main.cpp
	$(CMPL_CMD) -c main.cpp

StockQuoteGenerator.o: StockQuote.o StockQuoteGenerator.cpp
	$(CMPL_CMD) -c StockQuoteGenerator.cpp

StockQuote.o: StockQuote.cpp StockQuote.hpp
	$(CMPL_CMD) -c StockQuote.cpp

tinyxml2.o: tinyxml2/tinyxml2.cpp
	$(CMPL_CMD) -c tinyxml2/tinyxml2.cpp

test: test.o StockQuote.o
	$(CMPL_CMD) test.o StockQuote.o -o test

test.o: test.cpp
	$(CMPL_CMD) -c test.cpp 

clean:
	rm *.o
	rm squote
	rm test
