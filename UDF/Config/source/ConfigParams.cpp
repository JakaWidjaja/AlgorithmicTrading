#include "ConfigParams.h"

#include <string>

using std::stoi;
using std::string;

ConfigParams::ConfigParams(const string& filepath) : Config(filepath)
{
	loadExcel(filepath);
}

ConfigParams::~ConfigParams()
{}

void ConfigParams::loadExcel(const string& filepath)
{
	OpenXLSX::XLDocument doc;
	doc.open(filepath);
	auto sheet = doc.workbook().worksheet("Parameters");

	lookback = getValueByLabel(sheet, "lookback");
	interval = getValueByLabel(sheet, "interval");
}

string ConfigParams::getLookback() const
{
	return lookback;
}

string ConfigParams::getInterval() const
{
	return interval;
}