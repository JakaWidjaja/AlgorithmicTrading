#include "ConfigContract.h"

#include <string>
#include <optional>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using std::string;
using std::optional;
using std::vector;
using std::stod;
using std::remove_if;
using std::all_of;
using std::runtime_error;

ConfigContract::ConfigContract(const string& filepath) : Config(filepath)
{
	loadExcel(filepath);
}

ConfigContract::~ConfigContract()
{}

void ConfigContract::loadExcel(const string& filepath)
{
	OpenXLSX::XLDocument doc;
	doc.open(filepath);
	auto sheet = doc.workbook().worksheet("Contracts");

	bool firstRow = true;
	for(const auto& row : sheet.rows()) // Loop the rows. 
	{
		// Ignore first row
		if(firstRow)
		{
			firstRow = false;
			continue;
		}
		
		vector<OpenXLSX::XLCell> cells(row.cells().begin(), row.cells().end());
		if(cells.size() < 4 || cells[0].value().type() == OpenXLSX::XLValueType::Empty)
		{
			continue;
		}

		ContractContainer c;
		c.symbol   = cells[0].value().get<string>();
		c.secType  = cells[1].value().get<string>();
		c.exchange = cells[2].value().get<string>();
		c.currency = cells[3].value().get<string>();

		if(cells.size() > 4 && cells[4].value().type() != OpenXLSX::XLValueType::Empty)
		{
			c.expiry = cells[4].value().get<string>();
		}

		if(cells.size() > 5 && cells[5].value().type() != OpenXLSX::XLValueType::Empty)
		{
			c.right = cells[5].value().get<string>();
		}

		if(cells.size() > 6 && cells[6].value().type() != OpenXLSX::XLValueType::Empty)
		{
			c.strike = stod(cells[6].value().get<string>());
		}

		if(cells.size() > 7 && cells[7].value().type() != OpenXLSX::XLValueType::Empty)
		{
			c.multiplier = cells[7].value().get<string>();
		}

		if(cells.size() > 8 && cells[8].value().type() != OpenXLSX::XLValueType::Empty)
		{
			string val = cells[8].value().get<string>();
			val.erase(remove_if(val.begin(), val.end(), ::isspace), val.end()); // Remove spaces
			if(all_of(val.begin(),val.end(), ::isdigit))
			{
				if(val.length() == 6)
				{
					c.contractMonth = val;
				}
				else if(val.length() == 8)
				{
					c.lastTradeDate = val;
				}
				else
				{
					throw runtime_error("Invalid format for LastTradeDateOrContractMonth: " + val);
				}
			}
			else
			{
				throw runtime_error("Non-digit characters in LastTradeDateOrContractMonth: " + val);
			}
		}

		vecContracts.push_back(c);
	}
	doc.close();
}

const vector<ConfigContract::ContractContainer>& ConfigContract::getContracts() const
{
	return vecContracts;
}