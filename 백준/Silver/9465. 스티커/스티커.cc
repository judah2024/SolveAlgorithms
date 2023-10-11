#include <iostream>
#include <vector>

using namespace std;

long long DP(vector<vector<long long>>& dp, const int& n)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][j] += max(dp[i - 1][!j], max(dp[i - 2][0], dp[i - 2][1]));
        }
    }

    return max(dp[n][0], dp[n][1]);
}

int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<vector<long long>> dp(n + 1, vector<long long>(2));

        for (int upIdx = 1; upIdx <= n; upIdx++)
        {
            cin >> dp[upIdx][0];
        }

        for (int downIdx = 1; downIdx <= n; downIdx++)
        {
            cin >> dp[downIdx][1];
        }

        cout << DP(dp, n) << "\n";

    }

    return 0;
}