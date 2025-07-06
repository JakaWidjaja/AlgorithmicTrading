#include "CombinatoricsGenerator.h"
#include "Combinatorics.h"

#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;
using std::shared_ptr;

CombinatoricsGenerator::CombinatoricsGenerator(const vector<string>& tickers, shared_ptr<Combinatorics> method) : tickers(tickers), method(method)
{}


void CombinatoricsGenerator:: setMethod(shared_ptr<Combinatorics> newMethod)
{
	method = newMethod;
}

vector<vector<string>> CombinatoricsGenerator::compute(int num) const
{
	return method->generate(tickers, num);
}
