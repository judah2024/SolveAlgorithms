#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> CalculateLongIncrease(const int n, const vector<int>& a)
{
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j--)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    return dp;
}

int CalculateBitonic(const int n, vector<int>& a)
{
    vector<int> dp1 = CalculateLongIncrease(n, a);
    reverse(a.begin(), a.end());
    vector<int> dp2 = CalculateLongIncrease(n, a);
    reverse(dp2.begin(), dp2.end());

    int maxResult = 0;
    for (int i = 0; i < n; i++)
    {
        maxResult = max(maxResult, dp1[i] + dp2[i] - 1);
    }

    return maxResult;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << CalculateBitonic(n, a);

    return 0;
}