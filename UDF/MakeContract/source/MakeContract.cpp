#include "MakeContract.h"
#include "Config.h"
#include "ConfigContract.h"
#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

MakeContract::MakeContract(const string& filepath) : filepath(filepath)
{}

vector<Contract> MakeContract::contractList()
{
	Config config(filepath);

	shared_ptr<ConfigContract> contractConfig = config.getContractConfig();

	vector<Contract> contList;
	for(const auto& c : contractConfig -> getContracts())
	{
		Contract temp;
		temp.symbol   = c.symbol;
		temp.secType  = c.secType;
		temp.exchange = c.exchange;
		temp.currency = c.currency;

		if(c.expiry)
		{
			temp.lastTradeDateOrContractMonth = *c.expiry;
		}

		if(c.right)
		{
			temp.right = *c.right;
		}

		if(c.strike)
		{
			temp.strike = *c.strike;
		}

		if(c.multiplier)
		{
			temp.multiplier = *c.multiplier;
		}

		if(c.contractMonth)
		{
			temp.lastTradeDateOrContractMonth  = *c.contractMonth;
		}

		if(c.lastTradeDate)
		{
			temp.lastTradeDateOrContractMonth = *c.lastTradeDate;
		}

		contList.push_back(temp);
	}

	return contList;
}