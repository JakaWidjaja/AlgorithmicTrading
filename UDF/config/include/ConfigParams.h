#ifndef CONFIG_PARAMS_H
#define CONFIG_PARAMS_H

#include "Config.h"
#include "OpenXLSX/OpenXLSX.hpp"

class ConfigParams : public Config 
{
public:
	ConfigParams(const std::string& filepath);
	~ConfigParams();

	std::string getLookback() const;
	std::string getInterval() const;

private:
	void loadExcel(const std::string& filepath);
	std::string lookback;
	std::string interval;
};

#endif