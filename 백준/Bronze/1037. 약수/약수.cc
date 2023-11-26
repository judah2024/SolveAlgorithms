#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> ds(n);
    for (auto& it : ds)
    {
        cin >> it;
    }
    sort(ds.begin(), ds.end());

    cout << ds[0] * ds[n - 1];

    return 0;
}