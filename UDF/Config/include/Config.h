#ifndef CONFIG_H
#define CONFIG_H

#include "OpenXLSX/OpenXLSX.hpp"

#include <string>
#include <memory>

class ConfigTWS;
class ConfigModel;
class ConfigParams;
class ConfigContract;

class Config
{
public:
	Config(const std::string& filepath);
	virtual ~Config() = default;

	std::shared_ptr<ConfigTWS>      getTWSConfig() const;
	std::shared_ptr<ConfigModel>    getModelConfig() const;
	std::shared_ptr<ConfigParams>   getParamsConfig() const;
	std::shared_ptr<ConfigContract> getContractConfig() const;
	
protected:
	static std::string getValueByLabel(const OpenXLSX::XLWorksheet& sheet, const std::string& label);
	std::string filepath;
};

#endif