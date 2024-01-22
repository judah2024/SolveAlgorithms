#include <iostream>
#include <stack>

using namespace std;

long long CalculateFacePair(const int n)
{
	long long ans = 0;
	stack<pair<int, int>> stk;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;

		int cnt = 1;
		while (!stk.empty())
		{
			auto topInfo = stk.top();
			if (topInfo.first > m) break;
			if (topInfo.first == m) cnt += topInfo.second;
			ans += topInfo.second;
			stk.pop();
		}

		if (!stk.empty()) ans++;
		stk.push({ m, cnt });
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n;
	cin >> n;

	cout << CalculateFacePair(n);

	return 0;
}