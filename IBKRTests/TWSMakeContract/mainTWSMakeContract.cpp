#include "MakeContract.h"
#include "Contract.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() 
{
    // Config file path
    string configPath = "/home/lun/Desktop/Folder 2/AlgoTradingC++/config/configMeanRevertPortEOD.xlsx";

    MakeContract make(configPath);

    vector<Contract> contract = make.contractList();

    for(const auto& c : contract)
    {
        cout << "Symbol: "    << c.symbol
         << ", SecType: " << c.secType
         << ", Exchange: "<< c.exchange
         << ", Currency: "<< c.currency
         << ", Expiry: "  << c.lastTradeDateOrContractMonth
         << ", Strike: "  << c.strike
         << ", Right: "   << c.right
         << ", Multiplier: " << c.multiplier
         << endl;
    }

    return 0;
}