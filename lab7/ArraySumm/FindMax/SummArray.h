#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>

T ArraySum(std::vector<T> const& arr)
{
	if (arr.empty())
	{
		T value = T();
		return value;
	}

	auto sum = *arr.begin();

	for (auto it = arr.begin() + 1; it != arr.end(); ++it)
		sum = sum + *it;

	return sum;
}

