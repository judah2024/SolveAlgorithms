#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;

void PrintArray(vector<int>& nArray)
{
    for (auto& it : nArray)
    {
        cout << numbers[it] << " ";
    }
    cout << "\n";
}

void ExploreCombination(const int n, const int m, vector<int>& nArray)
{
    if (m == 0)
    {
        PrintArray(nArray);
        return;
    }

    int prevNumber = -1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && numbers[i] == prevNumber) continue;

        nArray.push_back(i);
        prevNumber = numbers[i];

        ExploreCombination(n, m - 1, nArray);

        nArray.pop_back();
    }
}

void PrintCombination(const int n, const int m)
{
    vector<int> nArray;

    nArray.reserve(m);

    ExploreCombination(n, m, nArray);
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