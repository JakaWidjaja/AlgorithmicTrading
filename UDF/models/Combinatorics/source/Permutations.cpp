#include "Permutations.h"

#include <vector>
#include <string>
#include <functional>

using std::vector;
using std::string;
using std::function;
using std::swap;

vector<vector<string>> Permutations::generate(const vector<string>& items, int num) const
{
	Combinations comb;
	auto combs = comb.generate(items, num);

	vector<vector<string>> results;

	function<void(vector<string>&, int)> permute = [&](vector<string>& arr, int leftIndex)
	{
		if(leftIndex == arr.size() - 1)
		{
			results.push_back(arr);
			return;
		}

		for(int i = leftIndex; i < arr.size(); ++i)
		{
			swap(arr[leftIndex], arr[i]);
			permute(arr, leftIndex + 1);
			swap(arr[leftIndex], arr[i]);
		}
	};

	for (auto& c : combs)
	{
		permute(c, 0);
	}

	return results;
}