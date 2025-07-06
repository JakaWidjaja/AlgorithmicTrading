#ifndef CONFIG_CONTRACT_H
#define CONFIG_CONTRACT_H

#include "Config.h"
#include "OpenXLSX/OpenXLSX.hpp"

#include <string>
#include <vector>
#include <optional>

class ConfigContract : public Config 
{
public:
	struct ContractContainer
	{
		std::string symbol;
		std::string secType;
		std::string exchange;
		std::string currency;
		std::optional<std::string> expiry;
		std::optional<std::string> right;
		std::optional<double>strike;
		std::optional<std::string> multiplier;
		std::optional<std::string> contractMonth;
		std::optional<std::string> lastTradeDate;
	};

	ConfigContract(const std::string& filepath);
	~ConfigContract();

	const std::vector<ContractContainer>& getContracts() const;

private:
	void loadExcel(const std::string& filepath);
	std::vector<ContractContainer> vecContracts;
};

#endif