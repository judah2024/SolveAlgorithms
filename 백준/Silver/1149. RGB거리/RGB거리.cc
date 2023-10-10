#include <iostream>
#include <vector>

using namespace std;

long long DP(const vector<vector<long long>>& costRGB, vector<vector<long long>>& dp)
{
    const int& n = costRGB.size();
    long long minCost;

    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = costRGB[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            long long min = 10000000;

            for (int k = 0; k < 3; k++)
            {
                if (k != j && min > dp[i - 1][k])
                {
                    min = dp[i - 1][k];
                }
            }

            dp[i][j] = costRGB[i][j] + min;
        }
    }

    minCost = min(dp[n - 1][0], dp[n - 1][1]);
    minCost = min(minCost, dp[n - 1][2]);

    return minCost;
}

int main()
{
    int n;
    vector<vector<long long>> dp;
    vector<vector<long long>> costRGB;

    cin >> n;
    dp.resize(n, vector<long long>(3));
    costRGB.resize(n, vector<long long>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> costRGB[i][j];
        }
    }

    cout << DP(costRGB, dp);

    return 0;
}
