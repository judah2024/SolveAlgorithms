#include <iostream>
#include <vector>

using namespace std;

long long CountListUniNumbers(const int n, const vector<int>& numbers)
{
	vector<bool> isUsing(100001, false);
	int i = 0, j = 0;
	long long ret = 0;
	for (i = 0; i < n; i++)
	{
		while (j < n)
		{
			auto& num = numbers[j];
			if (isUsing[num]) break;
			isUsing[num] = true;
			j++;
		}
		ret += (j - i);
		isUsing[numbers[i]] = false;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> numbers(n);
	for (auto& it : numbers)
	{
		cin >> it;
	}

	cout << CountListUniNumbers(n, numbers);

	return 0;
}