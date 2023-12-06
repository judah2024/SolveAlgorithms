#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& it : arr)
        cin >> it;

    sort(arr.begin(), arr.end(), greater<int>());

    for (auto& it : arr)
        cout << it << "\n";

    return 0;
}