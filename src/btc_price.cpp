#include <string>
#include <sstream>
#include <iostream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include "json.hpp"

const std::string CURRENCY = "EUR";

int main()
{
	std::ostringstream os;
	nlohmann::json j;

	try
	{
		curlpp::Cleanup myCleanup;
		curlpp::Easy myRequest;

		std::ostringstream os;
		os << curlpp::options::Url("https://blockchain.info/ticker");
        j = nlohmann::json::parse(os.str());
        if (j.find(CURRENCY) != j.end()) {
            std::cout << "Last price in " << CURRENCY << ": " << j[CURRENCY]["last"] << std::endl;
        }
	}

	catch(curlpp::RuntimeError & e)
	{
		std::cout << e.what() << std::endl;
	}

	catch(curlpp::LogicError & e)
	{
		std::cout << e.what() << std::endl;
	}
}
