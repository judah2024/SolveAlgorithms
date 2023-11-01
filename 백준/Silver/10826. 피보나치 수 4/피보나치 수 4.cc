#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string& operator+(string& a, string& b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int numSize = (a.size() > b.size() ? a.size() : b.size());

    a.resize(numSize, '0');
    b.resize(numSize, '0');

    for (int i = 0; i < numSize; i++)
    {
        int digit = (a[i] - '0') + (b[i] - '0');

        a[i] = (digit % 10 + '0');

        digit /= 10;
        if (digit)
        {
            if (i == numSize - 1)
            {
                a += '0';
            }

            a[i + 1] += digit;
        }

    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    string a("0"), b("1");

    for (int i = 0; i < n; i++)
    {
        swap(a, b);
        b = b + a;
    }

    cout << a;

    return 0;
}