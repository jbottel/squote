#include "StockQuote.hpp"
#include <boost/network/protocol/http/client.hpp>
#include "tinyxml2/tinyxml2.h"

namespace StockQuoteGenerator {
	StockQuote generateStockQuote(std::string request_symbol) {
		boost::network::http::client client;
		std::string requestURI = "http://finance.yahoo.com/webservice/v1/symbols/" + request_symbol + "/quote?view=detail";
		boost::network::http::client::request request(requestURI);
		request << boost::network::header("Connection", "close");
		boost::network::http::client::response response = client.get(request);
		std::string xml; 
		xml = body(response);

		tinyxml2::XMLDocument doc;
		doc.Parse(xml.c_str());

		tinyxml2::XMLElement* resourceElement = doc.FirstChildElement("list")->FirstChildElement("resources")->FirstChildElement("resource");

		if (resourceElement == nullptr) {
			StockQuote sq(0,0,0,0,"","FAILED",0,request_symbol,0,"","", 0, 0, 0);
			return sq;
		}

		double change; double chg_percent; double day_high; double day_low; double price; double ts; double volume; double year_high; double year_low;
		std::string issuer_name; std::string name; std::string symbol; std::string type; std::string utctime;
		for(tinyxml2::XMLElement* e = resourceElement->FirstChildElement("field"); e != NULL; e = e->NextSiblingElement("field")) {
			if (e->Attribute("name","change")) e->QueryDoubleText(&change);
			if (e->Attribute("name","chg_percent")) e->QueryDoubleText(&chg_percent);
			if (e->Attribute("name","day_high")) e->QueryDoubleText(&day_high);
			if (e->Attribute("name","day_low")) e->QueryDoubleText(&day_low);
			if (e->Attribute("name","price")) e->QueryDoubleText(&price);
			if (e->Attribute("name","ts")) e->QueryDoubleText(&ts);
			if (e->Attribute("name","volume")) e->QueryDoubleText(&volume);
			if (e->Attribute("name","year_high")) e->QueryDoubleText(&year_high);
			if (e->Attribute("name","year_low")) e->QueryDoubleText(&year_low);
			if (e->Attribute("name","issuer_name")) issuer_name = e->GetText();
			if (e->Attribute("name", "name")) name = e->GetText();
			if (e->Attribute("name", "symbol")) symbol = e->GetText();
			if (e->Attribute("name", "type")) type = e->GetText();
			if (e->Attribute("name", "utctime")) utctime = e->GetText();
		}

		StockQuote sq(change, chg_percent, day_high, day_low, issuer_name, name, price, symbol, ts, type, utctime, volume, year_high, year_low);

		return sq;


		
	}

}
