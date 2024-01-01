#include <iostream>
#include <vector>

using namespace std;

int CalculateMinSubtotalSize(const int n, const int s, const vector<int>& numbers)
{
	const int inf = 0x7fff'ffff;
	int i = 0, j = 0;
	int ret = inf;
	for (i = 0; i <= n; i++)
	{
		while (j <= n)
		{
			if (numbers[j] - numbers[i] >= s)
				break;

			j++;
		}

		if (j > n) break;

		ret = min(ret, j - i);
	}
	return ret == inf ? 0 : ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	vector<int> numbers(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> numbers[i];
		numbers[i] += numbers[i - 1];
	}

	cout << CalculateMinSubtotalSize(n, s, numbers);

	return 0;
}