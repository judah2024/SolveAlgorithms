#include <iostream>
#include <vector>

using namespace std;

long long CalculateModular(const long long& a, const long long& b, const long long& c)
{
    if (b == 0)
    {
        return 1;
    }

    long long n = a % c;
    long long r = CalculateModular(n * n, b / 2, c);

    if (b % 2 == 1)
    {
        r *= n;
    }

    return r % c;
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    
    cout << CalculateModular(a, b, c);

    return 0;
}