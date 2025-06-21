#ifndef MAKE_CONTRACT_H
#define MAKE_CONTRACT_H

#include "Contract.h"
#include <string>
#include <vector>
class MakeContract
{
public:
	MakeContract(const std::string& filepath);

	std::vector<Contract> contractList();

private:
	std::string filepath;
};

#endif