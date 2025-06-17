#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <vector>
#include <string>

class Combinatorics
{
public:
	virtual ~Combinatorics() = default;
	virtual std::vector<std::vector<std::string>> generate(const std::vector<std::string>& items, int num) const = 0;
};

#endif