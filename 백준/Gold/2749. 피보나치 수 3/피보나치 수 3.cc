#include <iostream>

using namespace std;

int main()
{
    const int divisor = 1'000'000;
    const int cycle = 1'500'000;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    n %= cycle;
    long long a = 0, b = 1;

    for (int i = 0; i < n; i++)
    {
        swap(a, b);
        b = (b + a) % divisor;
    }

    cout << a;

    return 0;
}