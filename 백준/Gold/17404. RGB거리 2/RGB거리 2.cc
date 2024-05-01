#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int DP(int n, vector<vector<int>>& colors)
{
	vector<vector<int>> dp(n, vector<int>(3, 0));

	int ret = INF;
	for (int s = 0; s < 3; ++s)
	{
		for (int i = 0; i < 3; ++i)
			dp[0][i] = (s == i ? colors[0][i] : INF);

		for (int e = 1; e < n; ++e)
		{
			dp[e][0] = colors[e][0] + min(dp[e - 1][1], dp[e - 1][2]);
			dp[e][1] = colors[e][1] + min(dp[e - 1][0], dp[e - 1][2]);
			dp[e][2] = colors[e][2] + min(dp[e - 1][0], dp[e - 1][1]);
		}
		
		auto& last = dp.back();
		last[s] = INF;
		for (const auto& it : last)
			ret = min(ret, it);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> colors(n, vector<int>(3));
	for (auto& c : colors)
		cin >> c[0] >> c[1] >> c[2];

	cout << DP(n, colors);

	return 0;
}