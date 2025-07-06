#ifndef CONFIG_MODEL_H
#define CONFIG_MODEL_H

#include "Config.h"
#include "OpenXLSX/OpenXLSX.hpp"

class ConfigModel : public Config 
{
public:
	ConfigModel(const std::string& filepath);
	~ConfigModel();

	int getCalibrationData() const;
	int getTopStocks() const;
	int getStockCombinations() const;
	int getHurstLag() const;
	int getVRLag() const;
	int getDoubleSMAShortWindow() const;
	int getDoubleSMALongWindow() const;
	int getStopLoss1() const;
	int getStopLoss2() const;
	int getProfitLimit() const;
	std::string getLongShortIndicator() const;
	int getInvestmentAmount() const;

private:
	void loadExcel(const std::string& filepath);
	int calibrationData;
	int topStocks;
	int stockCombinations;
	int hurstLag;
	int varianceRatioLag;
	int doubleSMAShortWindow;
	int doubleSMALongWindow;
	int stopLoss1;
	int stopLoss2;
	int profitLimit;
	std::string longShortIndicator;
	int investmentAmount;
};

#endif