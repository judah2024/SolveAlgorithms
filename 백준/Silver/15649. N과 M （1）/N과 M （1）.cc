#include <iostream>
#include <vector>

using namespace std;

void ExplorePermutation(const int n, const int m, vector<int>& nArray, vector<bool>& hasAlready)
{
    if (nArray.size() == m)
    {
        for (auto& it : nArray)
        {
            cout << it << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (hasAlready[i]) continue;

        nArray.push_back(i + 1);
        hasAlready[i] = true;

        ExplorePermutation(n, m, nArray, hasAlready);

        hasAlready[i] = false;
        nArray.pop_back();

    }
}

void PrintPermutation(const int n, const int m)
{
    vector<bool> hasAlready(n, false);
    vector<int> nArray;

    nArray.reserve(m);
    ExplorePermutation(n, m, nArray, hasAlready);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    PrintPermutation(n, m);

    return 0;
}