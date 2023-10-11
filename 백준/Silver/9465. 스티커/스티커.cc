#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

long long DP(vector<vector<long long>>& dp, const int& n)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][j] += max(dp[i - 1][!j], dp[i - 2][!j]);
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
        cin.ignore();
        vector<vector<long long>> dp(n + 1, vector<long long>(2));

        for (int j = 0; j < 2; j++)
        {
            string s;
            int idx = 1;

            getline(cin, s);
            stringstream ss(s);

            while (!ss.eof())
            {
                ss >> dp[idx++][j];
            }
        }

        cout << DP(dp, n) << "\n";

    }

    return 0;
}