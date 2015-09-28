#include <boost/network/protocol/http/client.hpp>
#include <string>
#include <iostream>
#include "tinyxml2/tinyxml2.h"


int main() {
        boost::network::http::client client;
        boost::network::http::client::request request("http://finance.yahoo.com/webservice/v1/symbols/MU/quote?view=detail");
        request << boost::network::header("Connection", "close");
        boost::network::http::client::response response = client.get(request);

	std::string xml; 
	xml = body(response);

	tinyxml2::XMLDocument doc;
	doc.Parse(xml.c_str());

	tinyxml2::XMLElement* resourceElement = doc.FirstChildElement("list")->FirstChildElement("resources")->FirstChildElement("resource");

	for(tinyxml2::XMLElement* e = resourceElement->FirstChildElement("field"); e != NULL; e = e->NextSiblingElement("field")) {
		std::string Name = e->Attribute("name");
		std::cout << Name << std::endl;
	}



}

