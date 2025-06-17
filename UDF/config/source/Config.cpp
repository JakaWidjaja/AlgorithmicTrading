#include "OpenXLSX/OpenXLSX.hpp"
#include "Config.h"
#include "ConfigTWS.h"
#include "ConfigModel.h"
#include "ConfigParams.h"
#include "ConfigContract.h"

#include <string>
#include <memory>
#include <sstream>
#include <iomanip>

using std::string;
using std::to_string;
using std::shared_ptr;
using std::make_shared;
using std::runtime_error;

Config::Config(const string& path) : filepath(path)
{}

string Config::getValueByLabel(const OpenXLSX::XLWorksheet& sheet, const string& label)
{
	for(uint64_t row = 1;; ++row)
	{
		auto cellA = sheet.cell("A" + to_string(row));
		if(cellA.value().type() == OpenXLSX::XLValueType::Empty) // empty string means end of the line
		{
			break;
		}

		string key = cellA.value().get<string>();
		if(key == label)
		{
			auto cellB = sheet.cell("B" + std::to_string(row));

            // Convert based on actual value type
            switch (cellB.value().type()) 
            {
                case OpenXLSX::XLValueType::String:
			        return cellB.value().get<std::string>();
			    case OpenXLSX::XLValueType::Integer:
			        return std::to_string(cellB.value().get<int64_t>());
			    case OpenXLSX::XLValueType::Float:
			    	{
			    		double excelTime = cellB.value().get<double>();
		                int total_seconds = static_cast<int>(excelTime * 24 * 60 * 60);
		                int hours = total_seconds / 3600;
		                int minutes = (total_seconds % 3600) / 60;
		                int seconds = total_seconds % 60;

		                std::ostringstream oss;
		                oss << std::setfill('0') << std::setw(2) << hours << ":"
		                    << std::setfill('0') << std::setw(2) << minutes << ":"
		                    << std::setfill('0') << std::setw(2) << seconds;
		                return oss.str();
			    	}
			    case OpenXLSX::XLValueType::Boolean:
			        return cellB.value().get<bool>() ? "true" : "false";
			    default:
			        throw std::runtime_error("Unsupported cell type for label: " + label);
            }
		}
	}
	throw runtime_error("Label '" + label + "' not found.");
}

shared_ptr<ConfigTWS> Config::getTWSConfig() const
{
	return make_shared<ConfigTWS>(filepath);
}

shared_ptr<ConfigModel> Config::getModelConfig() const
{
	return make_shared<ConfigModel>(filepath);
}

shared_ptr<ConfigParams> Config::getParamsConfig() const
{
	return make_shared<ConfigParams>(filepath);
}

shared_ptr<ConfigContract> Config::getContractConfig() const
{
	return make_shared<ConfigContract>(filepath);
}