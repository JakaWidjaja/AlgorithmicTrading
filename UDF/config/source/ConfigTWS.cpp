#include "ConfigTWS.h"

#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using std::string;
using std::to_string;
using std::runtime_error;
using std::stoi;


ConfigTWS::ConfigTWS(const std::string& filepath) : Config(filepath)
{
	loadExcel(filepath);
}

ConfigTWS::~ConfigTWS()
{}

void ConfigTWS::loadExcel(const string& filepath)
{
	OpenXLSX::XLDocument doc;
	doc.open(filepath);
	auto sheet = doc.workbook().worksheet("TWS");

	host            = getValueByLabel(sheet, "host");
	port            = stoi(getValueByLabel(sheet, "port"));
	clientId        = stoi(getValueByLabel(sheet, "client id"));
	marketOpenTime  = getValueByLabel(sheet, "market open time");
	marketCloseTime = getValueByLabel(sheet, "market close time");
	marketDataType  = stoi(getValueByLabel(sheet, "market data type"));

	doc.close();
}

string ConfigTWS::getHost() const
{
	return host;
}

int ConfigTWS::getPort() const
{
	return port;
}

int ConfigTWS::getClientId() const
{
	return clientId;
}

std::chrono::system_clock::time_point ConfigTWS::getMarketOpenTime() const
{
	std::tm tm = {};
	std::istringstream ss(marketOpenTime);
	ss >> std::get_time(&tm, "%H:%M:%S");
	if (ss.fail())
	{
		throw std::runtime_error("Failed to parse market open time: " + marketOpenTime);
	}

	// Fill current date
	std::time_t now  = std::time(nullptr);
	std::tm* timeNow = std::localtime(&now);
	tm.tm_year = timeNow->tm_year;
	tm.tm_mon  = timeNow->tm_mon;
	tm.tm_mday = timeNow->tm_mday;

	return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

std::chrono::system_clock::time_point ConfigTWS::getMarketCloseTime() const
{
	std::tm tm = {};
	std::istringstream ss(marketCloseTime);
	ss >> std::get_time(&tm, "%H:%M:%S");
	if(ss.fail())
	{
		throw std::runtime_error("Failed to parse market open time: " + marketCloseTime);
	}

	// Fill current date
	std::time_t now = std::time(nullptr);
	std::tm* timeNow = std::localtime(&now);
	tm.tm_year = timeNow->tm_year;
	tm.tm_mon  = timeNow->tm_mon;
	tm.tm_mday = timeNow->tm_mday;

	return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int ConfigTWS:: getMarketDataType() const
{
	return marketDataType;
}

