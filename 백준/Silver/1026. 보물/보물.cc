#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> InputArraydata(const int n)
{
    vector<int> nArray(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nArray[i];
    }

    return nArray;
}

int CalculateMininumSum(vector<int>& a, vector<int>& b, const int n)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] * b[i]);
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a = InputArraydata(n);
    vector<int> b = InputArraydata(n);

    cout << CalculateMininumSum(a, b, n);

    return 0;
}