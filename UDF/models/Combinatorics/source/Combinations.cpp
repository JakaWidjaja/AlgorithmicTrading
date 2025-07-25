#include "Combinations.h"

#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;
using std::function;

Combinations::~Combinations() = default;

vector<vector<string>> Combinations::generate(const vector<string>& items, int num) const
{
	vector<vector<string>> results;
	vector<string> current;

	if (num > static_cast<int>(items.size()) || num < 0) 
	{
    return {};  // no combinations possible
	}

	function<void(int, int)> combine = [&](int offset, int numLeft)
	{
		if(numLeft == 0)
		{
			results.push_back(current);
			return;
		}

		for(int i = offset; i <= items.size() - numLeft; ++i)
		{
			current.push_back(items[i]);
			combine(i + 1, numLeft - 1);
			current.pop_back();
		}
	};

	combine(0, num);
	return results;
}