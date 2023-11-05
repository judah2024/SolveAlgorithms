#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MakeFractal(vector<string>& fractal, int n, bool isEmpty, int x, int y)
{
    if (n == 1)
    {
        fractal[x][y] = (isEmpty ? ' ' : '*');
        return;
    }

    n /= 3;
    for (int i = 0; i < 9; i++)
    {
        bool EmptyFlag = (i == 4 ? true : false);

        MakeFractal(fractal, n, isEmpty || EmptyFlag, x + (i / 3) * n, y + (i % 3) * n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<string> fractal(n, string(n, '*'));

    MakeFractal(fractal, n, false, 0, 0);

    for (auto& it : fractal)
    {
        cout << it << "\n";
    }

    return 0;
}