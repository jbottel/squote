squote
======================

[![Build Status](https://travis-ci.org/jbottel/squote.svg?branch=master)](https://travis-ci.org/jbottel/squote)

``squote`` is a simple command line application to display quotes from the stock market. It is intended for system administrators or programmers who work on the command line but may also have a hobby of following/investing in the markets and would like to quickly check without needing to go to a browser window. Here's an example of a simple use of squote:

### Simple Quotes
![Simple use of squote](http://jbottel.github.io/squote/img/Simple.gif)

``squote`` can also display a more detailed set of information for those who really like numbers:

### Detailed View
![Simple use of squote](http://jbottel.github.io/squote/img/Detail.gif)


Development Notes
--------------
``squote`` is written entirely in C++ 11 and utilizes the following libraries:
- [boost](http://boost.org), especially:
  - boost::program_options
  - boost::system
  - boost::format
- [cpp-netlib](http://cpp-netlib.org/)
- [TinyXML2](http://www.grinninglizard.com/tinyxml2/)


Compiling ``squote``
--------------
The makefile is configured to compile squote on a linux system using clang++-3.5. g++ also compiles the program just fine. In order to dynamically link on Debian-based system you will need the following apt packages installed:
- libcppnetlib
- libssl
- libboost-thread
- libboost-program-options
- libboost-system
- libboost-regex
- libboost-test-dev


Stock Market Data
--------------
Market data is extracted from the public Yahoo! Finance API and ``squote`` should support any symbol that is supported by this API, certainly most symbols on NYSE and NASDAQ. This information is known to sometimes be up to 15 minutes old.
