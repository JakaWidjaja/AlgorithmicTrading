#ifndef COMBINATORICSGENERATOR_H
#define COMBINATORICSGENERATOR_H

#include "Combinatorics.h"
#include <vector>
#include <string>
#include <memory>

class CombinatoricsGenerator
{
public:
	CombinatoricsGenerator(const std::vector<std::string>& tickers, std::shared_ptr<Combinatorics> method);

	void setMethod(std::shared_ptr<Combinatorics> newMethod);
	std::vector<std::vector<std::string>> compute (int num) const;

private:
	std::vector<std::string> tickers;
	std::shared_ptr<Combinatorics> method;
};

#endif