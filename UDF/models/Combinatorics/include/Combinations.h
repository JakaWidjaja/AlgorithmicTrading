#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include "Combinatorics.h"
#include <vector>
#include <string>

class Combinations : public Combinatorics
{
public:
	std::vector<std::vector<std::string>> generate(const std::vector<std::string>& items, int num) const override;

};

#endif