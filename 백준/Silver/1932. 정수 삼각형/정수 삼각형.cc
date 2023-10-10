#include <iostream>
#include <vector>

using namespace std;

long long DP(vector<vector<long long>> dp, const int& n)
{
    long long maxNumber = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < dp[i].size() - 1; j++)
        {
            maxNumber = 0;
            for (int k = j - 1; k < j + 1; k++)
            {
                maxNumber = max(maxNumber, dp[i - 1][k]);
            }

            dp[i][j] += maxNumber;
        }
    }

    maxNumber = 0;
    for (int i = 1; i <= n; i++)
    {
        maxNumber = max(maxNumber, dp[n][i]);
    }

    return maxNumber;
}

int main()
{
    int n;
    vector<vector<long long>> dp;

    cin >> n;
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i].resize(i + 2, 0);

        for (int j = 1; j < dp[i].size() - 1; j++)
        {
            cin >> dp[i][j];
        }
    }

    cout << DP(dp, n);

    return 0;
}
