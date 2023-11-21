#include <iostream>
#include <numeric>

using namespace std;

const int dividor = 1000000007;

long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

long long PowB(long long a, int d)
{
    if (d == 1)
    {
        return a;
    }

    long long result = PowB(a * a % dividor, d / 2);
    if (d % 2 == 1)
    {
        result *= a;
    }
    return (result % dividor);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int m;
    cin >> m;
    long long result = 0;
    for (int i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;

        long long d = gcd(a, b);
        a /= d;
        b /= d;

        result += (PowB(a, dividor - 2) * b) % dividor;
    }

    cout << result % dividor;

    return 0;
}