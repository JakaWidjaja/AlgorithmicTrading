#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include "Combinatorics.h"
#include "Combinations.h"

#include <vector>
#include <string>

class Permutations : public Combinatorics
{
public:
	std::vector<std::vector<std::string>> generate(const std::vector<std::string>& items, int num) const override;
};

#endif