#include "ConfigModel.h"

#include <string>

using std::string;
using std::stoi;
using std::stod;

ConfigModel::ConfigModel(const string& filepath) :Config(filepath)
{
	loadExcel(filepath);
}

ConfigModel::~ConfigModel()
{}

void ConfigModel::loadExcel(const string& filepath)
{
	OpenXLSX::XLDocument doc;
	doc.open(filepath);
	auto sheet = doc.workbook().worksheet("Model");

	calibrationData      = stoi(getValueByLabel(sheet, "calibration data"));
	topStocks            = stoi(getValueByLabel(sheet, "top stocks"));
	stockCombinations    = stoi(getValueByLabel(sheet, "stock combinations"));
	hurstLag             = stoi(getValueByLabel(sheet, "hurst lag"));
	varianceRatioLag     = stoi(getValueByLabel(sheet, "variance ratio lag"));
	doubleSMAShortWindow = stoi(getValueByLabel(sheet, "double SMA short window"));
	doubleSMALongWindow  = stoi(getValueByLabel(sheet, "double SMA long window"));
	stopLoss1            = stod(getValueByLabel(sheet, "stop loss 1"));
	stopLoss2            = stod(getValueByLabel(sheet, "stop loss 2"));
	profitLimit          = stod(getValueByLabel(sheet, "profit limit"));
	longShortIndicator   = getValueByLabel(sheet, "long short indicator");
	investmentAmount     = stoi(getValueByLabel(sheet, "investment amount"));
}

int ConfigModel::getCalibrationData() const
{
	return calibrationData;
}

int ConfigModel::getTopStocks() const
{
	return topStocks;
}

int ConfigModel::getStockCombinations() const
{
	return stockCombinations;
}

int ConfigModel::getHurstLag() const
{
	return hurstLag;
}

int ConfigModel::getVRLag() const
{
	return varianceRatioLag;
}

int ConfigModel::getDoubleSMAShortWindow() const
{
	return doubleSMAShortWindow;
}

int ConfigModel::getDoubleSMALongWindow() const
{
	return doubleSMALongWindow;
}

int ConfigModel::getStopLoss1() const
{
	return stopLoss1;
}

int ConfigModel::getStopLoss2() const
{
	return stopLoss2;
}

int ConfigModel::getProfitLimit() const
{
	return profitLimit;
}

string ConfigModel::getLongShortIndicator() const
{
	return longShortIndicator;
}

int ConfigModel::getInvestmentAmount() const
{
	return investmentAmount;
}
