#include <iostream>
#include <vector>
#include <string>

using namespace std;

int DP(const string& a, const string& b)
{
    const int n = a.size();
    const int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << DP(a, b);

    return 0;
}