#ifndef CONFIG_TWS_H
#define CONFIG_TWS_H

#include "Config.h"
#include "OpenXLSX/OpenXLSX.hpp"

#include <string>
#include <chrono>

class ConfigTWS : public Config
{
public:
	ConfigTWS(const std::string& filepath);
	~ConfigTWS();

	std::string getHost() const;
	int getPort() const;
	int getClientId() const;
	int getMarketDataType() const;
	std::chrono::system_clock::time_point getMarketOpenTime() const;
	std::chrono::system_clock::time_point getMarketCloseTime() const;

private:
	std::string host;
	int port;
	int clientId;
	int marketDataType;
	std::string marketOpenTime;
	std::string marketCloseTime;

	void loadExcel(const std::string& filepath);

};

#endif