#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<bool> hasAlready;

void PrintArray(vector<int>& nArray)
{
    for (auto& it : nArray)
    {
        cout << numbers[it] << " ";
    }
    cout << "\n";
}

void ExploreCombination(const int n, const int m, const int index, vector<int>& nArray)
{
    if (nArray.size() == m)
    {
        PrintArray(nArray);
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (hasAlready[i]) continue;

        nArray.push_back(i);
        hasAlready[i] = true;

        ExploreCombination(n, m, i + 1, nArray);

        hasAlready[i] = false;
        nArray.pop_back();
    }
}

void PrintCombination(const int n, const int m)
{
    vector<int> nArray;

    nArray.reserve(m);
    hasAlready.resize(n, false);

    ExploreCombination(n, m, 0, nArray);
}

void InitializeNumbers(const int n)
{
    numbers.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    InitializeNumbers(n);
    PrintCombination(n, m);

    return 0;
}