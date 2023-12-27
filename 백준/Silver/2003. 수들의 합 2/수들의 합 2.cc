#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int CountSumCases(const int n, const int m, const vector<int>& numbers)
{
	int i = 0, j = 0, caseCnt = 0;

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		while (sum < m)
		{
			if (j == n)
				return caseCnt;

			sum += numbers[j++];
		}

		if (sum == m)
			caseCnt++;

		sum -= numbers[i];
	}
	return caseCnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n;
	long long m;
	cin >> n >> m;

	vector<int> numbers(n);
	for (auto& it : numbers)
	{
		cin >> it;
	}

	cout << CountSumCases(n, m, numbers);


	return 0;
}