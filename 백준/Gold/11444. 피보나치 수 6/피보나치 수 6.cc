#include <iostream>
#include <unordered_map>

using namespace std;

const int divisor = 1'000'000'007;
unordered_map<long long, long long> fibos;

void InitFibos()
{
    long long a = 0, b = 1;

    for (int i = 0; i < 1000; i++)
    {
        fibos[i] = a;

        swap(a, b);
        b = (b + a) % divisor;
    }
}

long long CalculateFibo(const long long n)
{
    if (!fibos[n])
    {
        long long result = 0;
        if (n % 2 == 1)
        {
            long long f1 = CalculateFibo(n / 2 + 1);
            long long f2 = CalculateFibo(n / 2);

            f1 = (f1 * f1) % divisor;
            f2 = (f2 * f2) % divisor;

            result = f1 + f2;
        }
        else
        {
            long long f1 = CalculateFibo(n / 2);
            long long f2 = CalculateFibo(n / 2 - 1);

            f2 = (f1 * f2) % divisor;
            f1 = (f1 * f1) % divisor;

            result = f1 + 2 * f2;
        }

        fibos[n] = result % divisor;
    }

    return fibos[n];
}

int main()
{
    InitFibos();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long n;
    cin >> n;

    cout << CalculateFibo(n);

    return 0;
}