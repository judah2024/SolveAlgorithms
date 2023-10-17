#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP(const vector<pair<int, int>>& items, const int n, const int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        int w = items[i].first;
        int v = items[i].second;

        for (int j = 1; j <= k; j++)
        {
            if (j - w < 0)
            {
                dp[i + 1][j] = dp[i][j];
            }
            else
            {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v);
            }
        }
    }

    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int w, v;
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        items[i] = { w, v };
    }

    cout << DP(items, n ,k);

    return 0;
}