#include <iostream>
#include <stack>

using namespace std;

long long CalculateMaxArea(const int n)
{
	long long ans = 0;
	stack<pair<long long, int>> stk;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;

		int idx = i;
		while (!stk.empty())
		{
			auto topInfo = stk.top();
			if (topInfo.first < h) break;
			ans = max(ans, (i - topInfo.second) * topInfo.first);
			idx = topInfo.second;
			stk.pop();
		}

		stk.push({ h, idx });
	}

	while (!stk.empty())
	{
		auto topInfo = stk.top();
		ans = max(ans, (n - topInfo.second) * topInfo.first);
		stk.pop();
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		cout << CalculateMaxArea(n) << "\n";
	}

	return 0;
}